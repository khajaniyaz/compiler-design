#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
 else { printf("Error: Mismatched Parentheses\n"); return; }
 } else if (isalnum(*p)) p++; // F ? id
 else { printf("Error: Invalid Character\n"); return; }
}
int main() {
 char input[100];
 printf("Enter expression: ");
 scanf("%s", input);
 p = input;
 E();
 if (*p) printf("Invalid Expression\n");
 else printf("Valid Expression\n");
 return 0;
}
