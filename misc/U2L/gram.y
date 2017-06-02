
%{
#include "../../includes/pch.h"
#include "../../includes/U2L/gram.tab.h"
#include "../../includes/U2L/flex.h"
#include "../../includes/U2L/bison.h"


#define YYERROR_VERBOSE
#define YYDEBUG 1


%}




%locations
%start program


%union
{
    int     int_const;
    char*   string_const;
    double  double_const;
    char*   id;
	char*   prop;
	

	class IdentifierNode* 		Identifier;
	class RequestMembersNode* 	RequestMembers;
	class ExprListNode*			ExprList;
	class ExprNode* 			Expr;
	class PredicateNode* 		Predicate;
	class TailNode* 			Tail;
	class HeadNode* 			Head;
	class RuleNode* 			Rule;
	class RulesListNode* 		RulesList;
	class SubgoalNode* 			Subgoal;
	class SubgoalListNode* 		SubgoalList;
	class ProgramNode* 			Program;
};

%type<Program> 		program;
%type<RulesList> 	rules_list;
%type<Rule> 		rule;
%type<Head> 		head;
%type<Tail> 		tail;
%type<SubgoalList> 	subgoal_list;
%type<Subgoal> 		subgoal;
%type<Predicate>	predicate;
%type<ExprList> 	expr_list;
%type<Expr> 		expr;
%type<RequestMembers> request_members;
%type<Identifier> 	identifier;

%token <int_const>    INT_CONST
%token <string_const> STRING_CONST
%token <double_const> DOUBLE_CONST
%token <id>           ID
%token <prop>         PROPERTY


%token ATMETA ATERRORS ATAPP ATBEH ATWARNINGS ATGLOBAL
%token _TRUE _FALSE ENDL
%token AND OR HENCE


%left ',' ';' '.'
%right ASSMNT MINUSASSMNT PLUSASSMNT
%left GT LT GTEQ LTEQ NEQ EQ
%left PLUS MINUS
%left MUL DIV
%left UMINUS
%nonassoc ']'
%nonassoc ')'



%%

program: rules_list {$$ = new ProgramNode($1); root = $$;root->action(); fprintf(logfile, "\n ALL");}
;

rules_list: /* empty */		{$$ = new RulesListNode();fprintf(logfile, "\n BISON: empty ->rules_list");}
| rule						{$$ = new RulesListNode($1);fprintf(logfile, "\n BISON: rule ->rules_list");}
| rules_list ENDL rule		{$1->addRule($3);fprintf(logfile, "\n BISON: rules_list ENDL rule ->rules_list");}
| rules_list ENDL			{$$ = $1;fprintf(logfile, "\n BISON: rule_list ENDL ->rules_list");}
;

rule: head HENCE tail '.' 		{$$ = new RuleNode($1, $3);fprintf(logfile, "\n BISON: head HENCE tail . ->rule");}
| head '.'						{$$ = new RuleNode($1);fprintf(logfile, "\n BISON: head . ->rule");}
;

head: predicate 				{$$ = new HeadNode($1);fprintf(logfile, "\n BISON: predicate->head");}
| predicate ENDL				{$$ = new HeadNode($1);fprintf(logfile, "\n BISON: predicate ENDL->head");}
;

tail: predicate 				{$$ = new TailNode($1);fprintf(logfile, "\n BISON: predicate->tail");}
| ENDL predicate				{$$ = new TailNode($2);fprintf(logfile, "\n BISON: predicate ENDL->tail");}
;

predicate: '[' subgoal_list ']'	{$$ = new PredicateNode($2);fprintf(logfile, "\n BISON: [ subgoal_list ]	->predicate ");}
;

subgoal_list: subgoal 			{$$ = new SubgoalListNode($1);fprintf(logfile, "\n BISON: subgoal->subgoal_list ");}
| subgoal_list ',' subgoal		{$1->addSubgoal($3,SubgoalNode::AND);fprintf(logfile, "\n BISON: subgoal_list , subgoal->subgoal_list ");}
| subgoal_list ';' subgoal		{$1->addSubgoal($3,SubgoalNode::OR);fprintf(logfile, "\n BISON: subgoal_list ; subgoal->subgoal_list ");}
;

subgoal: ENDL			{$$ = new SubgoalNode(); fprintf(logfile, "\n BISON: ENDL->subgoal ");}
| expr					{$$ = new SubgoalNode($1);fprintf(logfile, "\n BISON: expr->subgoal ");}
| predicate				{$$ = new SubgoalNode($1, SubgoalNode::predicate); fprintf(logfile, "\n BISON: predicate->subgoal ");}
| '!' predicate			{$$ = new SubgoalNode($2, SubgoalNode::not_predicate);fprintf(logfile, "\n BISON: !predicate->subgoal ");}
;


expr_list: expr			{$$ = new ExprListNode($1);fprintf(logfile, "\n BISON: expr->expr_list ");}
| expr_list ',' expr	{$1->addExpr($3);fprintf(logfile, "\n BISON: expr_list , expr->expr_list ");}
;

expr: identifier						{$$ = new ExprNode($1);fprintf(logfile, "\n BISON: %s ->expr",yylval.id);}
| expr PLUS expr						{$$ = new ExprNode($1, $3, ExprNode::expr_PLUS_expr);fprintf(logfile, "\n BISON: expr PLUS expr->expr ");}
| expr MINUS expr						{$$ = new ExprNode($1, $3, ExprNode::expr_MINUS_expr);fprintf(logfile, "\n BISON: expr MINUS expr->expr ");}
| expr MUL expr							{$$ = new ExprNode($1, $3, ExprNode::expr_MUL_expr);fprintf(logfile, "\n BISON: expr MUL expr->expr ");}
| expr DIV expr							{$$ = new ExprNode($1, $3, ExprNode::expr_DIV_expr);fprintf(logfile, "\n BISON: expr DIV expr->expr ");}
| expr ASSMNT expr						{$$ = new ExprNode($1, $3, ExprNode::expr_ASSMNT_expr);fprintf(logfile, "\n BISON: expr ASSMNT expr->expr ");}
| expr LT expr							{$$ = new ExprNode($1, $3, ExprNode::expr_LT_expr);fprintf(logfile, "\n BISON: expr LT expr->expr ");}
| expr GT expr							{$$ = new ExprNode($1, $3, ExprNode::expr_GT_expr);fprintf(logfile, "\n BISON: expr GT expr->expr ");}
| expr GTEQ expr						{$$ = new ExprNode($1, $3, ExprNode::expr_GTEQ_expr);fprintf(logfile, "\n BISON: expr GTEQ expr->expr ");}
| expr LTEQ expr						{$$ = new ExprNode($1, $3, ExprNode::expr_LTEQ_expr);fprintf(logfile, "\n BISON: expr LTEQ expr->expr ");}
| expr EQ expr							{$$ = new ExprNode($1, $3, ExprNode::expr_EQ_expr);fprintf(logfile, "\n BISON: expr EQ expr->expr ");}
| expr NEQ expr							{$$ = new ExprNode($1, $3, ExprNode::expr_NEQ_expr);fprintf(logfile, "\n BISON: expr NEQ expr->expr ");}
| _TRUE									{$$ = new ExprNode(true);fprintf(logfile, "\n BISON: true ->expr");}
| _FALSE								{$$ = new ExprNode(false);fprintf(logfile, "\n BISON: false ->expr");}
| INT_CONST								{$$ = new ExprNode(yylval.int_const);fprintf(logfile, "\n BISON: %d ->expr",yylval.int_const);}
| STRING_CONST							{$$ = new ExprNode(yylval.string_const);fprintf(logfile, "\n BISON: %s ->expr",yylval.string_const);}
| DOUBLE_CONST							{$$ = new ExprNode(yylval.double_const);fprintf(logfile, "\n BISON: %f ->expr",yylval.double_const);}
| identifier PLUSASSMNT expr 			{$$ = new ExprNode($1, $3, ExprNode::expr_plusassmnt_expr);fprintf(logfile, "\n BISON: identifier PLUSASSMNT expr -> expr");}
| identifier MINUSASSMNT expr 			{$$ = new ExprNode($1, $3, ExprNode::expr_minusassmnt_expr);fprintf(logfile, "\n BISON: identifier MINUSASSMNT expr -> expr");}
| request_members '(' expr_list ')' 	{$$ = new ExprNode($1, $3, ExprNode::request_members_expr_list);fprintf(logfile, "\n BISON: request_members( expr list ) -> expr");}
| request_members 						{$$ = new ExprNode($1, ExprNode::request_members);fprintf(logfile, "\n BISON: request_members -> expr");}
| '!' request_members '(' expr_list ')' {$$ = new ExprNode($2, $4, ExprNode::not_request_members_expr_list);fprintf(logfile, "\n BISON: !request_members( expr list ) -> expr");}
| '!' request_members					{$$ = new ExprNode($2, ExprNode::not_request_members);fprintf(logfile, "\n BISON: !request_members -> expr");}
;


request_members: identifier '.' identifier		{$$ = new RequestMembersNode($1,$3); fprintf(logfile, "\n BISON:  identifier . identifier -> request_members");}
| request_members '.' identifier				{$$ = new RequestMembersNode($1,$3); fprintf(logfile, "\n BISON:  request_members . identifier -> request_members");}
;

identifier: PROPERTY	{$$ = new IdentifierNode(IdentifierNode::property, yylval.prop); fprintf(logfile, "\n BISON:  PROPERTY %s -> identifier",yylval.prop);}
| ID				{$$ = new IdentifierNode(IdentifierNode::id, yylval.id); fprintf(logfile, "\n BISON:  ID %s -> identifier",yylval.id);}
| ATMETA 			{$$ = new IdentifierNode(IdentifierNode::atmeta); fprintf(logfile, "\n BISON:  ATMETA -> identifier");}
| ATGLOBAL			{$$ = new IdentifierNode(IdentifierNode::atglobal);fprintf(logfile, "\n BISON:  ATGLOBAL-> identifier");}
| ATBEH				{$$ = new IdentifierNode(IdentifierNode::atbeh);fprintf(logfile, "\n BISON:  ATBEH-> identifier");}
| ATAPP				{$$ = new IdentifierNode(IdentifierNode::atapp);fprintf(logfile, "\n BISON:  ATAPP-> identifier");}
| ATWARNINGS		{$$ = new IdentifierNode(IdentifierNode::atwarnings);fprintf(logfile, "\n BISON:  ATWARNINGS-> identifier");}
| ATERRORS			{$$ = new IdentifierNode(IdentifierNode::aterrors);fprintf(logfile, "\n BISON:  ATERRORS-> identifier");}
;


%%


void yyerror (char const* s)
{
    printf("%s\n",s);
    printf("ERROR on line: %d and column: %d", yylloc.first_line,yylloc.last_column);
    getchar();
    exit(0);
}

/*
int main (int argc, char* argv[])
{
    setlocale(LC_CTYPE, "russian");

    freopen("err.txt","w",stderr);

    logfile = fopen("log.txt", "w");

    yyin = fopen("../misc/U2L/input.ivl", "r");

    yyparse();

    fclose(logfile);

    // getchar();
    return 0;
}
*/