% {
#include<stdio.h>
int valid = 1;
%
}
%
token num id op
%
%
start: id '='
s ';'
s: id x
|
num x
|
'-'
num x
|
'('
s ')'
x
;
x: op s
|
'-'
s
|
;
%
%
int yyerror()

{
valid = 0;
printf("\nInvalid expression!\n");
return 0;
}
int main()
{
printf("\nEnter the expression:\n");
yyparse();
if (valid)
{
printf("\nValid expression!\n");
}
}
LEX part:
%
{
#include "y.tab.h"
%
}
%
%
[a - zA - Z_][a - zA - Z_0 - 9] *
return id;
[0 - 9] + (\.[0 - 9] * ) ?
return num;
[+
/*] return op;

. return yytext[0];
\n return 0;
%%
int yywrap()
{
return 1;
}