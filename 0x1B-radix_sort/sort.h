#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stddef.h>
#include <limits.h>

void print_array(const int *array, size_t size);

void radix_sort(int *array, size_t size);

int current_digit_sort(int *array, ssize_t size, int *tmp, long exp);



#endif
