21.count chars and lines words
%{
#include <stdio.h>
#include <ctype.h>
int char_count = 0, line_count = 0, word_count = 0;
%}
%%
\n { line_count++; }
[a-zA-Z0-9_]+ { word_count++; }
. { char_count++; }
%%
int main() {
 FILE *input_file = fopen("input.c", "r");
 if (!input_file) {
 printf("Error opening file\n");
 return 1;
 }
 yyin = input_file;
 yylex();
 fclose(input_file);
 printf("Characters: %d\nLines: %d\nWords: %d\n", char_count, line_count, word_count);
 return 0;
}


22.print constants  
%{
#include <stdio.h>
%}
%%
#define[ ]+[a-zA-Z_][a-zA-Z0-9_]*[ ]+[0-9]+ { printf("Constant: %s\n", yytext); }
[0-9]+ { printf("Constant: %s\n", yytext); }
. { }
%%
int main() { yylex(); }


23.count macros and headers
%{
#include <stdio.h>
int macro_count = 0, header_count = 0;
%}
%%
#define.* { macro_count++; }
#include.* { header_count++; }
. { }
%%
int main() {
 yylex();
 printf("Macros defined: %d\n", macro_count);
 printf("Header files included: %d\n", header_count);
 return 0;
}


24.print HTML tags
%{
#include <stdio.h>
%}
%%
<[^>]+> { printf("HTML Tag: %s\n", yytext); }
. { }
%%
int main() { yylex(); }


25.add line numbers and display same
%{
#include <stdio.h>
int line_number = 1;
%}
%%
. { printf("%d: %s", line_number++, yytext); }
%%
int main() { yylex(); return 0; }


26.count & remove comments
%{
#include <stdio.h>
int count = 0;
FILE *out;
%}
%%
\\/\\/.* | \\/\\[^]\\+([^/][^]\\+)*\\/ { count++; }
. { fputc(yytext[0], out); }
%%
int main() {
 out = fopen("output.c", "w");
 yylex();
 fclose(out);
 printf("Comments: %d\n", count);
}


27.identify capital words
%{
#include <stdio.h>
%}
%%
[A-Z]+ { printf("Capital Word: %s\n", yytext); }
. { }
%%
int main() { yylex(); }


28.email valid or not
%{
#include <stdio.h>
%}
%%
^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$ { printf("Valid Email Address: %s\n", yytext); }
. { printf("Invalid Email Address\n"); }
%%
int main() { yylex(); }

  
29. covert abc to ABC
%{
#include <stdio.h>
%}
%%
abc { printf("ABC"); }
. { printf("%s", yytext); }
%%
int main() { yylex(); }


30.check mobile number valid/not
%{
#include <stdio.h>
%}
%%
^[6-9][0-9]{9}$ { printf("Valid Mobile Number: %s\n", yytext); }
. { printf("Invalid Mobile Number\n"); }
%%
int main() { yylex(); }
