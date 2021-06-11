#ifndef _SORT_H
#define _SORT_H
#include <stdio.h>

void final_merge(int *array, int *left, int *right, size_t size);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif