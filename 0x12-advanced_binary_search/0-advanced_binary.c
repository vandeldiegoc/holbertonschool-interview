#include "search_algos.h"
/**
 * print_array - prints array binary search
 *
 * @array: sorted array of int.
 * @begin: begining index
 * @end: ending index
 *
 * Return: void.
 */
void print_array(int *array, size_t begin, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = begin; i < end; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}
/**
 * recursive_binary - helper of binary search adv function
 *
 * @array: sorted array of int.
 * @begin: begining index of the subarray
 * @end: ending index of the subarray
 * @value: value we are looking for
 *
 * Return: index, -1 if doesn't find it.
 */
int recursive_binary(int *array, size_t begin, size_t end, int value)
{
	size_t mid;

	print_array(array, begin, end);
	if (value == array[begin])
		return (begin);
	if (begin == end && array[begin] != value)
		return (-1);

	if (value == array[begin] && value == array[end])
	{
		if (value == array[begin - 1])
			return (recursive_binary(array, begin - 1, end, value));
		return (begin);
	}
	mid = (begin + end) / 2;
	if (value > array[mid])
	{
		return (recursive_binary(array, mid + 1, end, value));
	}
	else
	{
		return (recursive_binary(array, begin, mid, value));
	}
}
/**
 * advanced_binary - binary search algo
 *
 * @array: sorted array of int.
 * @size: size of the array.
 * @value: value we are looking for.
 *
 * Return: index of the fist value.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recursive_binary(array, 0, size - 1, value));
}
