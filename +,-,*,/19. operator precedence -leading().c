#include <stdio.h>
void leading(char c) {
 if (c == 'E') printf("LEADING(E) = { ( id }\n");
 else if (c == 'T') printf("LEADING(T) = { ( id }\n");
 else if (c == 'F') printf("LEADING(F) = { ( id }\n");
}
int main() {
 char c;
 printf("Enter Non-Terminal (E/T/F): ");
 scanf(" %c", &c);
 leading(c);
}
