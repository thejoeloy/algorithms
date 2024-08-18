#ifndef STRING_H
#define STRING_H

void naive_matcher(char* T, char* P);
void rk_matcher(char* T, char* P, int d, int q);
void kmp_matcher(char* T, char* P);
void compute_prefix_function(char* P, int pi[]);

#endif // STRING_H
