#include <stdio.h>
#include <string.h>
int t = 1;
void genTAC(char e[]) {
 for (int i = 0; e[i]; i++)
 if (strchr("=+-*/", e[i]))
 printf("t%d = %c %c %c\n", t++, e[i-1], e[i], e[i+1]);
}
int main() {
 char e[100]; printf("Enter expr: "), scanf("%s", e), genTAC(e); }
