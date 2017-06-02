#include "../../includes/U2L/bison.h"

bool isNewProperty;
ProgramNode* root;


QPointer<Result> IdentifierNode::action(QWidget *widget)
{

    Result* res = new Result();
    switch(m_type)
    {
    case IdentifierNode::atapp:
    {}break;
    case IdentifierNode::atbeh:
    {}break;
    case IdentifierNode::aterrors:
    {
        res->setResult(qVariantFromValue((void*)widget));
        res->setType("aterrors");
    }break;
    case IdentifierNode::atglobal:
    {}break;
    case IdentifierNode::atmeta:
    {
        QMetaObjectPtr metaObj = widget->metaObject();
        //QVariant var  = QVariant::fromValue(metaObj);
        QVariant var = qVariantFromValue(metaObj);

        res->setResult(var);
        res->setType("atmeta");

    }break;
    case IdentifierNode::atwarnings:
    {
        res->setResult(qVariantFromValue((void*)widget));
        res->setType("atwarnings");
    }break;
    case IdentifierNode::id:
    {   // type = QString
        res->setResult(QVariant(m_value));
        res->setType("id");
    }break;
    case IdentifierNode::property:
    {
        res->setResult(QVariant(m_value));
        res->setType("property");
    }break;
    default:
    {

    }

    }

    return QPointer<Result>(res);
}


// 0 - expr1 == expr2
// <0 - expr1 < expr2
// >0 -expr1 > expr2

int ExprNode::compareWith(ExprNode *other_node)
{
    int res;
    switch (other_node->getType())
    {
    case ExprNode::bool_const:
    {
        if(this->m_bool == other_node->m_bool){
            res = 0;
        }else if (this->m_bool == false)
        {
            res =-127;
        }else
        {
            res = 127;
        }


    }break;
    case ExprNode::int_const:
    {
        if(this->m_int == other_node->m_int){
            res = 0;
        }else if (this->m_int <  other_node->m_int)
        {
            res =-127;
        }else
        {
            res = 127;
        }
    }break;
    case ExprNode::double_const:
    {
        if(fabs(this->m_double - other_node->m_double) <= DBL_EPSILON){
            res = 0;
        }else if (this->m_double - other_node->m_double < 0)
        {
            res = -127;
        }else{
            res = 127;
        }
    }break;
    case ExprNode::string_const:
    {
        res = getString().compare(other_node->m_string);
    }break;


    default:{}
    }

    return res;
}

void ExprNode::setValue(QVariant value)
{
    switch (value.type())
    {
    case QVariant::Bool:
    {
        this->m_type = ExprNode::bool_const;
        this->m_bool = value.value<bool>();
    }break;
    case QVariant::String:
    {
        this->m_type = ExprNode::string_const;
        setString(value.value<QString>());
    }break;
    case QVariant::Int:
    {
        this->m_type = ExprNode::int_const;
        this->m_int = value.value<int>();
    }break;
    case QVariant::Double:
    {
        this->m_type = ExprNode::double_const;
        this->m_double = value.value<double>();
    }break;
    default:{}
    }
}

QPointer<Result> ExprListNode::action(QWidget* widget)
{
    Result* res = new Result();

    QListIterator<ExprNode*> it(m_expr_list);
    while(it.hasNext())
    {
        ExprNode* curNode = it.next();
        Result* curRes = curNode->action(widget);
        if (curRes->success == Result::No)
        {
            res->success = Result::Yes;
            break;
        }
    }

    return QPointer<Result> (res);
}

QPointer<Result> RequestMembersNode::action(QWidget *widget)
{
    Result* res = new Result();

    if (getType() == RequestMembersNode::Identifier_Identifier)
    {
        Result* res1 = this->m_id1->action(widget);
        Result* res2 = this->m_id2->action(widget);
        QString metaMethodName = res2->getResult().toString();

        if (res1->getType() == "atmeta"){


            if (metaMethodName.startsWith("className"))
            {
                //QMetaObjectPtr ptr = static_cast<QMetaObjectPtr>(res1->getResult().value<void*>());
                QMetaObjectPtr ptr = res1->getResult().value<QMetaObjectPtr>();
                QString className = ptr->className();
                qDebug() << "className:" << qPrintable(className);
                res->success = Result::Yes;
                res->setResult(QVariant(className));
            }
        }


    }
    return QPointer<Result>(res);
}

QPointer<Result> ExprNode::action(QWidget *widget)
{
    Result* res = new Result();


    switch(this->m_type)
    {
    case ExprNode::identifier:
    {
        IdentifierNode::Type type = m_identifier1->m_type;
        switch(type)
        {
        case IdentifierNode::property:
        {
            QString nameOfProp = m_identifier1->getValue();
            const QMetaObject* metaObj =  widget->metaObject();
            int countProp = metaObj->propertyCount();
            res->success = Result::No;
            for (int i=0;i<countProp;i++)
            {
                QMetaProperty curMetaProp = metaObj->property(i);
                if (QString(curMetaProp.name()) == nameOfProp)
                {
                    QVariant var = curMetaProp.read(widget);
                    res->setResult(var);
                    res->setType(var.typeName());
                    res->success = Result::Yes;
                    break;
                }
            }
        }break;
        }
    }break;
    case ExprNode::expr_GT_expr:
    {
        int compareRes = this->m_expr1->compareWith(this->m_expr2);
        if (compareRes > 0)
        {
            res->success = Result::Yes;
        }else
        {
            res->success = Result::No;
        }

    }break;
    case ExprNode::expr_LT_expr:
    {
        int compareRes = this->m_expr1->compareWith(this->m_expr2);
        if (compareRes < 0)
        {
            res->success = Result::Yes;
        }else
        {
            res->success = Result::No;
        }

    }break;
    case ExprNode::expr_NEQ_expr:
    {
        int compareRes = this->m_expr1->compareWith(this->m_expr2);
        if (compareRes != 0)
        {
            res->success = Result::Yes;
        }else
        {
            res->success = Result::No;
        }
    }break;
    case ExprNode::expr_EQ_expr:
    {
        Result* res1 =  this->m_expr1->action(widget);
        Result* res2 =  this->m_expr2->action(widget);

        qDebug() << "1: " << res1->getResult().toString();
        qDebug() << "2: " << res2->getResult().toString();
        if (res1->success && res2->success){
            this->m_expr1->setValue(res1->getResult());
            this->m_expr2->setValue(res2->getResult());

            int compareRes = this->m_expr1->compareWith(this->m_expr2);
            if (compareRes == 0)
            {
                res->success = Result::Yes;
            }else
            {
                res->success = Result::No;
            }
        }else
        {
            res->success = Result::No;
        }
    }break;
    case ExprNode::string_const:
    {
        const QString& str = getString();
        res->setResult(QVariant(str));
        res->setType("string");
        res->success = Result::Yes;
    }break;
    case ExprNode::double_const:
    {
        res->setResult(QVariant(m_double));
        res->setType("double");
        res->success = Result::Yes;
    }break;
    case ExprNode::int_const:
    {
        res->setResult(QVariant(m_int));
        res->setType("int");
        res->success = Result::Yes;
    }break;
    case ExprNode::bool_const:
    {
        res->setResult(QVariant(m_bool));
        res->setType("bool");
        res->success = Result::Yes;
    }break;
    case ExprNode::expr_plusassmnt_expr:
    {
        Result* res1 = this->m_identifier1->action(widget);
        Result* res2 = this->m_expr2->action(widget);
        QWidget* wgt = (QWidget*)res1->getResult().value<void*>();
        if (res1->getType() == "aterrors" && res2->getType() == "string")
        {
            QStringList list = errors.value((QObject*)wgt);
            list.append(res2->getResult().toString());
            errors.insert((QObject*)widget,list);
            res->success = Result::Yes;
        }else if (res1->getType() == "atwarnings" && res2->getType() == "string")
        {
            QStringList list = warnings.value((QObject*)wgt);
            list.append(res2->getResult().toString());
            warnings.insert((QObject*)widget,list);
            res->success = Result::Yes;
        }
    }break;
    case ExprNode::request_members:
    {
        res = m_request_members->action(widget);
        res->success = Result::Yes;
    }break;
    default:
    {}
    }

    return QPointer<Result>(res);
}

QPointer<Result> SubgoalNode::action(QWidget *widget)
{
    Result* res = new Result();
    if (this->m_type == SubgoalNode::predicate)
    {
        res = this->m_predicate->action(widget);
    }else if (this->m_type == SubgoalNode::expr)
    {
        res = this->m_expr->action(widget);
    }else if(this->m_type == SubgoalNode::not_predicate)
    {
        res = this->m_expr->action(widget);
        res->success = (Result::Success)!res->success;
    }else
    {
        res->success = Result::Yes;
    }
    return QPointer<Result>(res);
}

QPointer<Result> SubgoalListNode::action(QWidget *widget)
{
    Result* res = new Result();
    QListIterator<SubgoalNode*> it(this->m_subgoals_list);
    while(it.hasNext())
    {
        SubgoalNode* curSubgoal = it.next();
        res = curSubgoal->action(widget);
        if (res->success == Result::No)
        {
            break;
        }
    }
    return QPointer<Result>(res);
}

QPointer<Result> PredicateNode::action(QWidget *widget)
{
    return this->m_subgoal_list->action(widget);
}

QPointer<Result> TailNode::action(QWidget *widget)
{
    return this->m_predicate->action(widget);
}
QPointer<Result> HeadNode::action(QWidget *widget)
{
    return this->m_predicate->action(widget);
}
QPointer<Result> RuleNode::action(QWidget *widget)
{
    Result* res = new Result();
    res  = this->m_head->action(widget);
    if (this->m_type == RuleNode::head_only)
    {
        res->success = Result::Yes;
    }else if (this->m_type == RuleNode::head_tail)
    {
        if (res->success == Result::Yes)
        {
            this->m_tail->action(widget);
        }
    }

    return QPointer<Result>(res);

}

// TODO Сделать так, чтобы внутренний цикл проходил по правилам, а не по виджетам
QPointer<Result> RulesListNode::action(QWidget *widget)
{
    Q_UNUSED(widget)
    QListIterator<RuleNode*> it(this->m_rules_list);

    while(it.hasNext()){
        RuleNode* curRule = it.next();

        QListIterator<QWidget*> it2(widgetsList);
        while(it2.hasNext())
        {
            QWidget* curWidget = it2.next();
            qDebug() << "ObjectName: " << curWidget->objectName();
            QString dstr = curWidget->objectName();
            qDebug() << "RulesListNode::action::metaClassName :" << curWidget->metaObject()->className();
            curRule->action(curWidget);
        }
    }
    return QPointer<Result>(new Result());
}

QPointer<Result> ProgramNode::action(QWidget* widget)
{
    return m_rules_list->action(widget);
}
