#include <stdio.h>
int main() {
 char A, alpha[10], beta[10];
 scanf("%c=%[^|]|%s", &A, alpha, beta);
 if (alpha[0] == A)
 printf("%c->%s%c'\n%c'->%s%c'|ε\n", A, beta, A, A, alpha + 1, A);
 else
 printf("No left recursion.\n");
}
