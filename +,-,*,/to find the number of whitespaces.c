#include <stdio.h>
int main() {
 char *c = "Hello World\n This is a test\n";
 int ws = 0, nl = 0;
 while (*c) ws += *c == ' ', nl += *c++ == '\n';
 printf("Whitespaces: %d\nNewlines: %d\n", ws, nl);
}
