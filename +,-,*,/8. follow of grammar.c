#include <stdio.h>
#include <string.h>
char p[10][10], f[10][10], flw[10][10]; int n;
void first(char c, int i) {
 if (c < 'A' || c > 'Z') strncat(f[i], &c, 1);
 for (int j = 0; j < n; j++) if (p[j][0] == c)
 for (int k = 2; p[j][k]; k++) { first(p[j][k], i); if (p[j][k] < 'A') break; }
}
void follow(char c, int i) {
 if (p[0][0] == c) strcat(flw[i], "$");
 for (int j = 0; j < n; j++)
 for (int k = 2; p[j][k]; k++)
 if (p[j][k] == c) p[j][k+1] ? first(p[j][k+1], i) : follow(p[j][0], i);
}
int main() {
 scanf("%d", &n);
 for (int i = 0; i < n; i++) scanf("%s", p[i]), first(p[i][0], i), follow(p[i][0], i);
 for (int i = 0; i < n; i++) printf("FOLLOW(%c)={%s}\n", p[i][0], flw[i]);
}
