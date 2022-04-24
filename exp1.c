#include<stdio.h>
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
int i, j, k, p, len, s_cntr = 1, l_cntr = 1, s = 0, l = 0, c = 0, LC = 1000;
char line[50], newsym[10], mnemonics[10], s_l, s_l_no;
char MT[5][10] = {
"LOAD",
"STORE",
"ADD",
"DEC",
"JNZ"
};
char OT[5][10] = {
"2A",
"1D",
"BC",
"23",
"34"
};
struct symbol_table ST[5];
struct literal_table LT[5];
char IC[10][20];
char input[15][20] = {
"START",
"N1 DB 05H",
"LOAD ='03'",
"STORE COUNT",
"LOAD N1",
"REPEAT: ADD N1",
"DEC COUNT",
"JNZ REPEAT",
"LTORG ='03'",

"STORE RESULT",
"END",
"RESULT DB ?",
"COUNT DB ?"
};
for (i = 0; i < 13; i++) {
strcpy(line, input[i]);
// Process symbols
if (strstr(line, "DB") != NULL) {
j = 0;
k = 0;
while (line[j] != ' ') {
newsym[k] = line[j];
j++;
k++;
}
newsym[k] = '\0';
ST[s].sym_no = s_cntr;
strcpy(ST[s].sym, newsym);
ST[s].addr = LC;
s++;
s_cntr++;
}
// Process labels
if (strstr(line, ":") != NULL) {
j = 0;
k = 0;
while (line[j] != ':') {
newsym[k] = line[j];
j++;
k++;
}
newsym[k] = '\0';
ST[s].sym_no = s_cntr;
strcpy(ST[s].sym, newsym);
ST[s].addr = LC;
s++;
s_cntr++;
}
// Process literals
if (strstr(line, "LTORG") != NULL) {
strcpy(newsym, "");
j = 0;

k = 0;
while (line[j] != ' ')
j++;
j++;
while (line[j] != '\0') {
newsym[k] = line[j];
j++;
k++;
}
newsym[k] = '\0';
LT[l].lit_no = l_cntr;
strcpy(LT[l].lit, newsym);
LT[l].addr = LC;
l++;
l_cntr++;
}
LC++;
}
for (i = 0; i < 13; i++) {
strcpy(line, input[i]);
// Create Intermediate code
for (j = 0; j < 5; j++) {
strcpy(mnemonics, MT[j]);
if (strstr(line, mnemonics) != NULL) {
len = strlen(line);
k = 0;
p = len - 1;
while (line[p] != ' ') {
newsym[k] = line[p];
p--;
k++;
}
newsym[k] = '\0';
strrev(newsym);
s_l_no = ' ';
// find in symbol table
for (k = 0; k < s; k++) {
if (strcmp(newsym, ST[k].sym) == 0) {
s_l = 'S';
s_l_no = ST[k].sym_no + '0';
}
}
// find in literal table
if (s_l_no == ' ') {
for (k = 0; k < l; k++) {
if (strcmp(newsym, LT[k].lit) == 0) {
s_l = 'L';

s_l_no = LT[k].lit_no + '0';
}
}
}
strcpy(IC[c], OT[j]);
strcat(IC[c], " 01 ");
strncat(IC[c], & s_l, 1);
strncat(IC[c], & s_l_no, 1);
c++;
}
}
}
printf("\n Symbol Table is...\n");
printf("\nSym No. Symbol\tAddress");
for (i = 0; i < s; i++)
printf("\n%d\t %s\t %d", ST[i].sym_no, ST[i].sym, ST[i].addr);
printf("\n\n Literal Table is...\n");
printf("\nLit No. Literal\tAddress");
for (i = 0; i < l; i++)
printf("\n%d\t %s\t %d", LT[i].lit_no, LT[i].lit, LT[i].addr);
printf("\n\n Intermediate Code is...\n");
for (i = 0; i < c; i++)
printf("\n%s", IC[i]);
}