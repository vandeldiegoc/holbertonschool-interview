#include "sort.h"

/**
 * swap - Swaps array values
 * @a: array first value
 * @b: array second value
 * @array: Array to print
 * @size: size of the array
 * Return:
 */
void swap(int *array, int a, int b, size_t size)
{
int tmp = array[a];
array[a] = array[b];
array[b] = tmp;
print_array(array, size);

}


/**
 * heapity_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of binary tree
 * @i: index node
 * @real_size: size of the array
 */
void heapity_sort(int *array, size_t size, size_t i, size_t real_size)
{
size_t max = i;
size_t left_child = 2 * i + 1;
size_t right_child = 2 * i + 2;
if (left_child < size && array[left_child] > array[max])
max = left_child;

if (right_child < size && array[right_child] > array[max])
max = right_child;

if (max != i)
{
swap(array, i, max, real_size);
heapity_sort(array, size, max, real_size);
}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
int i = 0;
for (i = size / 2 - 1; i >= 0; i--)
heapity_sort(array, size, i, size);

for (i = size - 1; i >= 0; i--)
{
if (i != 0)
swap(array, 0, i, size);
heapity_sort(array, i, 0, size);
}
}
