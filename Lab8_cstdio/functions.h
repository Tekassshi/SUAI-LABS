#ifndef FUNCTIONS
#define FUNCTIONS
#include <cstdio>;

bool fisopen(FILE* input_file, FILE* output_file);
bool iscontains(char symbarr[], char symb);
void filter(FILE* input_file, FILE* output_file, char symbarr[]);

#endif