#include <stdio.h>
int main() {
 for (char *c = "a=b+c*d-e/f;"; *c; c++)
 if (*c == '+' || *c == '-' || *c == '*' || *c == '/')
 printf("'%c' is an operator\n", *c);
}
