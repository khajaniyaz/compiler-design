#include <stdio.h>
#include <ctype.h>
int isValid(char *s) {
 if (!isalpha(*s) && *s != '_') return 0;
 while (*++s) if (!isalnum(*s) && *s != '_') return 0;
 return 1;
}
int main() {
 char id[] = "var1";
 puts(isValid(id) ? "Valid" : "Invalid");
}
