#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "db_type","db_name","db_table_prefex","db_port"};

int main(){

  int ntoken,vtoken;
  ntoken = yylex();
  while(ntoken)
  {
	printf("%d\n",ntoken);
	if(yylex() != COLON){
	printf("syntax error in line %d, Expected a ':' but found %s\n",yylineno,yytext);	
	}
	ntoken = yylex();
  }
  return 0;
}
