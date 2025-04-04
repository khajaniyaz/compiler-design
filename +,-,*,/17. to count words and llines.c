#include <stdio.h>
#include <ctype.h>
int main() {
 FILE *fp = fopen("input.txt", "r");
 if (!fp) return printf("File not found\n"), 1;
 int c, chars = 0, words = 0, lines = 0, inWord = 0;
 while ((c = fgetc(fp)) != EOF) chars++, lines += (c == '\n'), words += (!isspace(c) && !inWord) ? inWord
= 1 : isspace(c) ? inWord = 0 : 0;

 fclose(fp);
 printf("Chars: %d\nWords: %d\nLines: %d\n", chars, words, lines);
}
