#ifndef BISON_H
#define BISON_H

#include "../../includes/pch.h"

class Result;
class Node;
class IdentifierNode;
class RequestMembersNode;
class ExprNode;
class ExprListNode;
class PredicateNode;
class TailNode;
class HeadNode;
class RuleNode;
class RulesListNode;
class SubgoalNode;
class SubgoalListNode;
class ProgramNode;

extern "C" int yyparse();

extern "C" void yyerror (char const* s);

extern "C" FILE *yyin;

extern QHash<QObject*, QStringList> errors;
extern QHash<QObject*, QStringList> warnings;

extern bool isNewProperty;

extern ProgramNode* root;

extern QWidgetList widgetsList;


typedef const QMetaObject* QMetaObjectPtr;

Q_DECLARE_METATYPE(QMetaObjectPtr)


class Node
{
    virtual QPointer<Result> action(QWidget* widget = 0) = 0;
};


class IdentifierNode : public Node
{


    QString m_value;

public:
    enum Type{
        id,
        property,
        atmeta,
        atglobal,
        atapp,
        aterrors,
        atwarnings,
        atbeh
    };
    enum Type m_type;

    explicit IdentifierNode();
    explicit IdentifierNode(enum Type in_type){m_type = in_type;}
    explicit IdentifierNode(enum Type in_type, QString value){m_type = in_type; m_value = value;}

    QPointer<Result> action(QWidget *widget);

    const QString& getValue()
    {return m_value;}

    void setValue(QString newValue)
    {m_value = newValue;}
};

// TODO make pointers constant
class RequestMembersNode : public Node
{
    IdentifierNode* m_id1;
    IdentifierNode* m_id2;
    RequestMembersNode* m_rm1;
    enum Type{
        Identifier_Identifier,
        RequestMembers_Identifier
    };
    enum Type m_type;

public:

    explicit RequestMembersNode();
    explicit RequestMembersNode(IdentifierNode* id1, IdentifierNode* id2)
    {m_type = Identifier_Identifier,  m_id1 = id1, m_id2 = id2;}
    explicit RequestMembersNode(RequestMembersNode* rm1, IdentifierNode* id2)
    {m_type = RequestMembers_Identifier, m_rm1 = rm1, m_id2 = id2;}

    QPointer<Result> action(QWidget *widget);
    enum Type getType(){return m_type;}
};

class ExprListNode : public Node
{
    QList<ExprNode*> m_expr_list;

public:
    explicit ExprListNode(ExprNode* expr)
    {m_expr_list.append(expr);}

    void addExpr(ExprNode* expr)
    {m_expr_list.append(expr);}


    QPointer<Result> action(QWidget* widget);
};

class ExprNode : public Node
{
    IdentifierNode* m_identifier1;

    ExprNode* m_expr1;
    ExprNode* m_expr2;

    RequestMembersNode* m_request_members;

    ExprListNode* m_expr_list;

    QString m_string;
    int m_int;
    double m_double;
    bool m_bool;

public:

    enum Type{
        identifier,
        expr_EQ_expr,
        expr_NEQ_expr,
        expr_LTEQ_expr,
        expr_GTEQ_expr,
        expr_LT_expr,
        expr_GT_expr,
        expr_PLUS_expr,
        expr_MINUS_expr,
        expr_DIV_expr,
        expr_MUL_expr,
        expr_ASSMNT_expr,
        string_const,
        int_const,
        double_const,
        bool_const,
        request_members,
        request_members_expr_list,
        not_request_members_expr_list,
        not_request_members,
        expr_plusassmnt_expr,
        expr_minusassmnt_expr
    };


    enum Type m_type;


public:
    explicit ExprNode();

    explicit ExprNode(IdentifierNode* identifier)
    {m_type = ExprNode::identifier, m_identifier1 = identifier;}

    explicit ExprNode(const char* string_const)
    {m_type = ExprNode::string_const,m_string = string_const;}

    explicit ExprNode(int int_const)
    {m_type = ExprNode::int_const,  m_int = int_const;}

    explicit ExprNode(double double_const)
    {m_type = ExprNode::double_const,  m_double = double_const;}

    explicit ExprNode(bool bool_const)
    {m_type = ExprNode::bool_const,  m_bool = bool_const;}

    explicit ExprNode(ExprNode* expr1, ExprNode* expr2, ExprNode::Type type)
    {m_type = type,  m_expr1 = expr1, m_expr2 = expr2;}

    explicit ExprNode(IdentifierNode* ident1, ExprNode* expr2, ExprNode::Type type)
    {m_type = type,  m_identifier1 = ident1, m_expr2 = expr2;}

    explicit ExprNode(RequestMembersNode* request_members, ExprNode::Type type)
    {m_type = type, m_request_members = request_members;}

    explicit ExprNode(RequestMembersNode* request_members, ExprListNode* list, ExprNode::Type type)
    {m_type = type, m_request_members = request_members; m_expr_list = list;}

    QPointer<Result> action(QWidget *widget);

    int compareWith(ExprNode* other_node);

    enum Type getType(){return m_type;}

    const QString& getString()
    {
        const QString& res = m_string;
        return res;
    }
    void setString(const QString& inStr)
    {
        m_string = inStr;
    }

    void setValue(QVariant value);

};

class SubgoalNode : public Node
{
    ExprNode* m_expr;
    PredicateNode* m_predicate;

public:

    enum Type{
        endl,
        expr,
        predicate,
        not_predicate
    };
    enum RelationWithPrev{
        NOTSET,
        AND,
        OR
    };
    explicit SubgoalNode(){m_type = (Type)endl;m_relation_with_prev=NOTSET;}
    explicit SubgoalNode(ExprNode* in_expr)
    {m_type = SubgoalNode::expr; m_expr = in_expr;m_relation_with_prev=NOTSET;}
    explicit SubgoalNode(PredicateNode* in_predicate, enum Type in_type)
    {m_type = (Type)in_type, m_predicate = in_predicate;m_relation_with_prev=NOTSET;}

    void setRelationWithPrev(RelationWithPrev in_relation)
    {m_relation_with_prev = in_relation;}

    QPointer<Result> action(QWidget *widget);
private:
    enum Type m_type;

    enum RelationWithPrev m_relation_with_prev;

};

class SubgoalListNode : public Node
{
    QList<SubgoalNode*> m_subgoals_list;

public:
    explicit SubgoalListNode();
    explicit SubgoalListNode(SubgoalNode* in_subgoal) : m_subgoals_list()
    {m_subgoals_list.append(in_subgoal);}

    void addSubgoal(SubgoalNode* in_subgoal, enum SubgoalNode::RelationWithPrev in_relation)
    {m_subgoals_list.append(in_subgoal); in_subgoal->setRelationWithPrev(in_relation);}

    QPointer<Result> action(QWidget *widget);
};

class PredicateNode : public Node
{
    SubgoalListNode* m_subgoal_list;

public:
    explicit PredicateNode();
    explicit PredicateNode(SubgoalListNode* in_subgoal_list)
    {m_subgoal_list = in_subgoal_list;}
    QPointer<Result> action(QWidget *widget);
};

class TailNode : public Node
{
    PredicateNode* m_predicate;

public:
    explicit TailNode();
    explicit TailNode(PredicateNode* in_predicate)
    {m_predicate = in_predicate;}
    QPointer<Result> action(QWidget *widget);
};

class HeadNode : public Node
{
    PredicateNode* m_predicate;

public:
    explicit HeadNode();
    explicit HeadNode(PredicateNode* in_predicate)
    {m_predicate = in_predicate;}

    QPointer<Result> action(QWidget *widget);
};

class RuleNode : public Node
{
    HeadNode* m_head;
    TailNode* m_tail;


public:
    enum Type{
        head_tail,
        head_only
    };
    enum Type m_type;
    explicit RuleNode();
    explicit RuleNode(HeadNode* in_head, TailNode* in_tail)
    {m_head = in_head, m_tail = in_tail, m_type = head_tail;}
    explicit RuleNode(HeadNode* in_head)
    {m_head = in_head, m_type = head_only;}

    QPointer<Result> action(QWidget *widget);
};

class RulesListNode : public Node
{
    QList<RuleNode*> m_rules_list;

public:
    explicit RulesListNode() : m_rules_list()
    {}

    explicit RulesListNode(RuleNode* in_rule) : m_rules_list()
    {m_rules_list.append(in_rule);}

    void addRule(RuleNode* in_rule)
    {m_rules_list.append(in_rule);}

    QPointer<Result> action(QWidget* widget = 0);

};

class ProgramNode : public Node
{
    RulesListNode* m_rules_list;
public:
    explicit ProgramNode();
    explicit ProgramNode(RulesListNode* in_rules)
    {m_rules_list = in_rules;}

    QPointer<Result> action(QWidget* widget = 0);
};

class Result : public QObject
{
    Q_OBJECT


    QVariant m_result;
    QString m_type;
public:

    explicit Result(QObject *parent = 0) : QObject(parent)
    {success = Result::Yes;}
    explicit Result(QVariant variant){m_result = variant;}
    explicit Result(QVariant variant, QString nameOfType){m_result = variant, m_type = nameOfType;}

    QVariant getResult(){return m_result;}

    void setResult( QVariant result){m_result = result;}
    void setType(QString newType){m_type = newType;}
    QString getType(){return m_type;}

    enum Success{
        No = 0,
        Yes = 1
    };
    enum Success success;

    QVariant* operator->() {
        return &m_result;
    }

};


#endif // BISON_H
