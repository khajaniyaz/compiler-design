#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
 char code[] = "int a = 5 + 3;", *t = strtok(code, " ;=");
 while (t) printf("%s is a %s\n", t, isalpha(*t) ? "identifier" : isdigit(*t) ? "constant" : "operator"), t =
strtok(NULL, " ;=");
}
