#include <stdio.h>
int main() {
 char line[100];
 printf("Enter a line of code: ");
 fgets(line, sizeof(line), stdin);
 printf("%s\n", line[0] == '/' ? (line[1] == '/' ? "Single-line comment" : line[1] == '*' ? "Multi-line comment" :
"Not a comment") : "Not a comment");
}
