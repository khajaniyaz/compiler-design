#include <stdio.h>
int main() {
 char A, alpha[10], beta[10];
 scanf("%c=%[^|]|%s", &A, alpha, beta);
 printf("%c->%cX\nX->%s|e\n", A, A, beta);
}
