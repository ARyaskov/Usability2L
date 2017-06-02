%option noyywrap
%option never-interactive
%option yylineno

%{

#include "../../includes/U2L/flex.h"
#include "../../includes/U2L/gram.tab.h"

#define YY_NO_UNISTD_H

char commentBuf[2000];
char literal[1000];
int integer;
double doubl;
int res;
FILE* logfile;
FILE* errfile;

#define YYDEBUG 1

int yycolumn = 1;

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng; \
    yylval.string_const = strdup(yytext);
	
%}

%x COMMENT
%x STRING1
%%



"@meta"					{fprintf(logfile,"\n met @meta \n");return ATMETA;}
"@beh"					{fprintf(logfile,"\n met @beh \n");return ATBEH;}
"@app"					{fprintf(logfile,"\n met @app \n");return ATAPP;}
"@global"			    {fprintf(logfile,"\n met @global \n");return ATGLOBAL;}
"@warnings"				{fprintf(logfile,"\n met @warnings \n");return ATWARNINGS;}
"@errors"			    {fprintf(logfile,"\n met @errors \n");return ATERRORS;}

"true"				    {fprintf(logfile,"\n met true \n");return _TRUE;}
"false"			 	    {fprintf(logfile,"\n met false \n");return _FALSE;}

"+="				    {fprintf(logfile,"\n met += \n");return PLUSASSMNT;}
"-="			 	    {fprintf(logfile,"\n met -= \n");return MINUSASSMNT;}			

"+"						{fprintf(logfile,"\n met + \n");return PLUS;}
"-"						{fprintf(logfile,"\n met - \n");return MINUS;}
"*"						{fprintf(logfile,"\n met * \n");return MUL;}
"/"						{fprintf(logfile,"\n met / \n");return DIV;}

"="						{fprintf(logfile,"\n met = \n");return ASSMNT;}

"=="					{fprintf(logfile,"\n met == \n");  return EQ;}
"!="					{fprintf(logfile,"\n met != \n"); return NEQ;}
"<"						{fprintf(logfile,"\n met < \n"); return LT;}
">"						{fprintf(logfile,"\n met > \n"); return GT;}
"<="					{fprintf(logfile,"\n met <= \n"); return LTEQ;}
">="					{fprintf(logfile,"\n met >= \n"); return GTEQ;}

":-"					{fprintf(logfile,"\n met :- \n"); return HENCE;}

"["					{fprintf(logfile,"\n met Open square bracket \n"); return '[';}
"]"					{fprintf(logfile,"\n met close square bracket \n"); return ']';}


"("					{fprintf(logfile,"\n met open parenthesis\n"); return '(';}
")"					{fprintf(logfile,"\n met close parenthesis\n"); return ')';}

"!"						{fprintf(logfile,"\n met ! \n"); return '!';}
","						{fprintf(logfile,"\n met comma \n"); return ',';}
";"                     {fprintf(logfile,"\n met semicolon \n"); return ';';}
"."                     {fprintf(logfile,"\n met dot \n"); return '.';}
"|"                     {fprintf(logfile,"\n met | \n"); return '|';}

[\n]+                   {
                          fprintf(logfile,"\n met ENDL");
                          return ENDL;
                          yylineno++;
                          }


[0-9]+					{fprintf(logfile,"\n met int number: %d",atoi(yytext));
                        yylval.int_const = atoi(yytext);
						return INT_CONST;}


[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?  {

                                           yylval.double_const = atof(yytext);
				                           fprintf(logfile,"\n met double: %f",atof(yytext));
                                           return DOUBLE_CONST;
				                   }

@[A-Za-z]+[0-9A-Za-z]*  {
          fprintf(logfile,"\n met PROPERTY: %s",yytext);
          yylval.prop = (char*)malloc(strlen(yytext));
		  strcpy(yylval.prop, yytext+1);
		  res = PROPERTY;
		  return res;
}
								   
[A-Za-z]+[0-9A-Za-z]*  {
          fprintf(logfile,"\n met ID: %s",yytext);
          yylval.id = (char*)malloc(strlen(yytext));
		  strcpy(yylval.id, yytext);
		  res = ID;
		  return res;
}


\"						{ strcpy(literal,""); BEGIN(STRING1);}
<STRING1>[^\"]+			{ strcat(literal, yytext);}
<STRING1>\"				{
  fprintf(logfile,  "\n met string: \"%s\"", literal);
  yylval.string_const = (char*)malloc(strlen(literal));
  strcpy(yylval.string_const, literal);
  res = STRING_CONST;

  BEGIN(INITIAL);
  return res;
  }


"//" 			{BEGIN(COMMENT);}
<COMMENT>\n+ 	{BEGIN(INITIAL);}
  
%%
/*
int main(){
  setlocale(LC_CTYPE, "rus");
 // freopen("log.txt","w+",stdout);
  logfile = fopen("log.txt", "w");
  yyin = fopen("input.ivl", "r");
  yylex();
  fclose(logfile);
 // fclose(stdout);
  return 0;
  }
 */