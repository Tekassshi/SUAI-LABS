#ifndef FUNCTIONS
#define FUNCTIONS
#include <fstream>

bool fisopen(std::ifstream* in, std::ofstream* out);
bool iscontains(char symbarr[], char symb);
void filter(std::ifstream* in, std::ofstream* out, char symbarr[]);

#endif