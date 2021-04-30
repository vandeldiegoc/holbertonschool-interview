#ifndef __SEARCH_ALGOS_H__
#define __SEARCH_ALGOS_H__

#include <stdio.h>
#include <stdlib.h>


void print_array(int *array, size_t begin, size_t end);
int recursive_binary(int *array, size_t begin, size_t end, int value);
int advanced_binary(int *array, size_t size, int value);

#endif