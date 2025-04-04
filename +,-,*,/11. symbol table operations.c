#include <stdio.h>
#include <string.h>
struct S {
 char n[20], t[10];
} T[10];
int N = 0;
void insert(char *n, char *t) {
 strcpy(T[N].n, n);
 strcpy(T[N++].t, t);
}
void search(char *n) {
 for (int i = 0; i < N; i++) {
 if (!strcmp(T[i].n, n)) {
 printf("Found: %s (%s)\n", n, T[i].t);
 return;
 }
 }
 printf("Not Found\n");
}
void display() {
 for (int i = 0; i < N; i++)
 printf("%s -> %s\n", T[i].n, T[i].t);
}
int main() {
 insert("x", "int");
 insert("y", "float");
 search("x");
 display();
 return 0;
}
