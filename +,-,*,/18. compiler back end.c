#include <stdio.h>
#include <string.h>
int t = 1;
void genCode(char *e) {
 for (int i = 0; e[i]; i++)
 if (strchr("=+-*/", e[i]))
 printf("MOV R%d, %c\n%c R%d, %c\n", t, e[i-1], e[i], t++, e[i+1]);
}
int main() {
 char e[100];
 scanf("%s", e), genCode(e);
}
