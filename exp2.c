#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct symbol_table {
int sym_no;
char sym[10];
int addr;
};
struct literal_table {
int lit_no;
char lit[10];
int addr;
};
void main() {
int i, j, k, p, len, addr;
char s_l, s_l_no, line[50], ch, temp[20];
struct symbol_table ST[] = {
{
1,
"N1",
1000
},
{
2,
"REPEAT",
1004
},
{
3,
"RESULT",
1009
},
{
4,
"COUNT",
1010
}
};
struct literal_table LT[] = {
{
1,
"='03'",
1007

}
};
char IC[15][20] = {
{
"2A 01 L 1"
},
{
"1D 01 S 4"
},
{
"2A 01 S 1"
},
{
"BC 01 S 1"
},
{
"23 01 S 4"
},
{
"34 01 S 2"
},
{
"1D 01 S 3"
}
};
char MAC[15][20];
for (i = 0; i < 7; i++) {
for (j = 0; j < 6; j++)
MAC[i][j] = IC[i][j];
MAC[i][j] = '\0';
}
for (i = 0; i < 7; i++) {
strcpy(line, IC[i]);
if ((strstr(line, " S ") != NULL) || (strstr(line, " L ") != NULL)) {
len = strlen(line);
s_l = line[len - 3];
s_l_no = line[len - 1];
}
// if operand is a symbol
if (s_l == 'S') {
for (j = 0; j < 4; j++) {
if (s_l_no == ST[j].sym_no + '0')
addr = ST[j].addr;
}
} else {

// if operand is a literal
if (s_l == 'L') {
for (j = 0; j < 1; j++) {
if (s_l_no == LT[j].lit_no + '0')
addr = LT[j].addr;
}
}
}
itoa(addr, temp, 10);
strcat(MAC[i], temp);
printf("\n%s", MAC[i]);
}
printf("\n Machine code is\n");
for (i = 0; i < 7; i++)
printf("\n%s", MAC[i]);
}