%{
 
 
#undef yywrap
#define yywrap() 1
 
%}
 
 
%%
 
 
[\n] {
 printf("Hello World\n"); 
}
 
 
%%
 
 
main()
{
 yylex(); //calling the rules section
}

/* lex exp5.l */
/* gcc -lfl lex.yy.c */
/* ./a.out */
/* press ctrl+d to end */