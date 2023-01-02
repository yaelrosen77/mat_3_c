#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

int get_line(char s[]);
int getword(char w[]);
int similar(char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);
