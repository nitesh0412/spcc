% {
#include<stdio.h> #undef yywrap #define yywrap() 1
%
}
%
% [\n] {
printf("\n\nPls give the input: ");
}
auto | double | int | struct |
break |
else |long |
switch |
case |enum | register | typedef | char | extern | r eturn | union |
continue |
for | signed | void | do |
if | static |
while |
default | goto | sizeof | volatile | co nst | float | short {
printf("This is Keywords");
}
[a - z A - Z _][a - z A_Z 0 - 9 _] * {
printf("This is Identifier");
} [0 - 9] * {
printf("This is Number");
}
[+ -
/*%=] {printf("This is Operator");}
.* {printf("Invalid");}

%%
int main()
{
printf("\nInput: "); yylex();
return 0;
}