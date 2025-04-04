#include <stdio.h>
#include <ctype.h>
#include <string.h>
char p[10][10], f[10][10]; int n;
void first(char c, int i) {
 if (!isupper(c)) strncat(f[i], &c, 1);
 for (int j = 0; j < n; j++)
 if (p[j][0] == c) for (int k = 2; p[j][k]; k++) {
 first(p[j][k], i);
 if (!isupper(p[j][k])) break;
 }
}
int main() {
 scanf("%d", &n);
 for (int i = 0; i < n; i++) scanf("%s", p[i]), first(p[i][0], i);
 for (int i = 0; i < n; i++) printf("F(%c)={%s}\n", p[i][0], f[i]);
}
