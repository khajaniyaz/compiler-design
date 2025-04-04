32,33.count vowels
%{
#include <stdio.h>
int vowel_count = 0;
%}
%%
[aeiouAEIOU] { vowel_count++; }
. { }
%%
int main() {
 yylex();
 printf("Vowel Count: %d\n", vowel_count);
}


31,34.separate keywords and identifiers
%{
#include <stdio.h>
int isKeyword(char *str) {
 char *keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return", "void"};
 for (int i = 0; i < 9; i++) {
 if (!strcmp(str, keywords[i])) return 1;
 }
 return 0;
}
%}
%%
[a-zA-Z_][a-zA-Z0-9_]* {
 if (isKeyword(yytext))
 printf("Keyword: %s\n", yytext);
 else
 printf("Identifier: %s\n", yytext);
}
. { }
%%
int main() { yylex(); }


35.recognize numbers and words in statement
%{
#include <stdio.h>
%}
%%
[0-9]+ { printf("Number: %s\n", yytext); }
[a-zA-Z]+ { printf("Word: %s\n", yytext); }
. { }
%%
int main() { yylex(); }


36.count positive and negative numbers
%{
#include <stdio.h>
int pos = 0, neg = 0;
%}
%%
[+-]?[0-9]+ { if (yytext[0] == '-') neg++; else pos++; }
. { }
%%
int main() { yylex(); printf("Positive: %d, Negative: %d\n", pos, neg); }


37.validate url
%{
#include <stdio.h>
%}
%%
(http|https)://[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}(/[a-zA-Z0-9._/-]*)? { printf("Valid URL: %s\n", yytext); }
.* { printf("Invalid URL\n"); }
%%
int main() { yylex(); }


38. validate dob
%{
#include <stdio.h>
%}
%%
([0-2][0-9]|3[0-1])[-](0[1-9]|1[0-2])[-](19[0-9]{2}|20[0-2][0-9]) { printf("Valid DOB: %s\n", yytext); }
.* { printf("Invalid DOB\n"); }
%%
int main() { yylex(); }


39. check digit
%{
#include <stdio.h>
%}
%%
[0-9] { printf("Digit\n"); }
. { printf("Not a Digit\n"); }
%%
int main() { yylex(); }


40. Math operations
%{
#include <stdio.h>
%}
%%
[0-9]+|[\+\-\*/] { printf("%s\n", yytext); }
%%
int main() { yylex(); }
