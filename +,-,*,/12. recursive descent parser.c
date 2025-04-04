#include <stdio.h>
#include <ctype.h>
char *p;
void E(), E_(), T(), T_(), F();
void E() { T(); E_(); }
void E_() { if (*p == '+') { p++; T(); E_(); } }
void T() { F(); T_(); }
void T_() { if (*p == '*') { p++; F(); T_(); } }
void F() {
 if (*p == '(') {
 p++;
 E();
 if (*p == ')') p++;
 else { printf("Error\n"); return; }
 } else if (isalnum(*p)) p++;
 else { printf("Error\n"); return; }
}
int main() {
 char input[100];
 printf("Enter expression: ");
 scanf("%s", input);
 p = input;
 E();
 if (*p) printf("Invalid\n");
 else printf("Valid\n");
 return 0;
}
