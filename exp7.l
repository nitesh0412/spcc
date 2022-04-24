%{
 #include<stdio.h>
%}

%%
[\n] {printf("\n\nPls give the input: ");}

auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|sizeof|volatile|const|float|short {printf("This is Keywords");}

[a-z A-Z _][a-z A_Z 0-9 _]* {printf("This is Identifier");}

[0-9]* {printf("This is Number");}

[+-/*%=] {printf("This is Operator");}

.* {printf("Invalid");}

%%

main()
{
 printf("\nPls give the input: ");
 yylex();
 return 0;
}

/* lex exp7.l */
/*gcc -lfl lex.yy.c */
/* ./a.out */