#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void commentRemoval(FILE *input,FILE *output);
void headerFileInclusion(FILE *src, FILE *des);
void process_macros(FILE *input, FILE *output);
