#include <ctype.h>
void clean(char *c) {
 char *p = c, *q = c;
 while (*p) {
 if (*p == '/' && (*(p+1) == '*' || *(p+1) == '/')) while (*p && (*p != '\n' && *(p-1) != '/')) p++;
 if (!isspace(*p) || (q > c && !isspace(*(q-1)))) *q++ = *p;
 p++;
 }
 *q = '\0';
}
int main() {
 char c[] = "/*comment*/ int main(){int a=10;//comment\n printf(\"Hi\");\n}";
 clean(c);
 printf("%s", c);
}
