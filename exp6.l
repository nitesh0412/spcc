% {
#include<stdio.h> #include<string.h>
int lc = 0,
tc = 0,
ch = 0,
sc = 0; %
} %
% \n lc++;
([]) sc++;\
t tc++;
.ch++; %
%
int main() {
yylex();
printf("Number of lines are %d\n", lc);
printf("Number of spaces are %d\n", sc);
printf("Number of tabs are %d\n", tc);
printf("Number of characters are %d\n", ch);
return 0;
}