#include <stdio.h>
#include <string.h>
char stack[100]; int top = -1;
void shift(char c) { stack[++top] = c; }
void reduce() { if (top >= 2 && (stack[top-1] == '+' || stack[top-1] == '*') && stack[top-2] == 'E') top -= 2;
else if (top >= 2 && stack[top] == ')' && stack[top-2] == '(') top -= 2; else if (top >= 0 && stack[top] == 'i')
stack[top] = 'E'; }
int main() {
 char input[100]; printf("Enter input: "), scanf("%s", input);
 for (int i = 0; i < strlen(input); i++) shift(input[i]), reduce();
 printf(top == 0 && stack[top] == 'E' ? "Valid\n" : "Invalid\n");
}
