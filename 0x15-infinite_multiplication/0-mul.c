#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
/**
 * main - gets the number and multiplication.
 *
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	char *a = argv[1];
	char *b = argv[2];
	int *num1, *num2, *res;
	int len_a, len_b;

	if (argc != 3)
	{
		print_error();
		exit(98);
	}
	check_input(argv);

	len_a = _strlen(a);
	len_b = _strlen(b);

	num1 = NULL;
	num2 = NULL;
	res = NULL;

	num1 = myalloc(num1, len_a);
	num2 = myalloc(num2, len_b);

	store_in_array(strrev(a), num1);
	store_in_array(strrev(b), num2);

	res = multiplication(num1, num2, len_a, len_b);
	print_array(res, len_a + len_b);

	free(num1);
	free(num2);
	free(res);
	return (0);
}
/**
 * multiplication - multiplies reversed numbers
 *
 * @num1: array 1 of number reversed.
 * @num2: array 2 of number reversed.
 * @len1: length of num1.
 * @len2: length of num2.
 *
 * Return: rev(num1) * rev(num2).
 */
int *multiplication(int *num1, int *num2, int len1, int len2)
{
	int len, i, j;
	int *r;

	len = len1 + len2;
	r = NULL;
	r = myalloc(r, len);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2; j >= 0; j--)
		{
			r[i + j + 1] += num1[len1 - 1 - i] * num2[len2 - 1 - j];
		}
	}

	for (i = len - 1; i >= 0; i--)
	{
		if (r[i] >= 10)
		{
			r[i - 1] += r[i] / 10;
			r[i] = r[i] % 10;
		}
	}
	return (r);
}
/**
 * store_in_array - stores a string numbers in arrays by digits
 *
 * @str: string we want to store.
 * @array: array we want to store the number in.
 *
 * Return: Nothing.
 */
void store_in_array(char *str, int *array)
{
	int i;

	for (i = 0; i < _strlen(str); i++)
	{
		array[i] = str[i] - '0';
	}
}
/**
 * print_array - prints a number takes from array of digits.
 *
 * @num: array we want to print.
 * @len: length of the array.
 *
 * Return: Nothing.
 */
void print_array(int *num, int len)
{
	int i;

	i = 0;
	while (num[i] == 0)
		i++;
	if (i >= len)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}
	for (; i < len; i++)
	{
		_putchar(num[i] + '0');
	}
	_putchar('\n');
}
/**
 * strrev - reverses a string.
 *
 * @str: string we want to reverse.
 *
 * Return: string reversed.
 */
char *strrev(char *str)
{
	char *p1, *p2;

	if (!str || !*str)
		return (str);
	for (p1 = str, p2 = str + _strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return (str);
}
/**
 * _strlen - computes he length of a string.
 *
 * @s: string we want to compute its length
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/**
 * init_zero - initilises all array to zeros.
 *
 * @a: array of integers.
 * @len: length of the array a.
 *
 * Return: Nothing
 */
void init_zero(int *a, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		a[i] = 0;
	}
}
/**
 * print_error - prints 'error' to stdout.
 *
 * Return: Nothing.
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
}

/**
 * myalloc - allocates space for an array and initializes it.
 *
 * @n: pointer to initialize.
 * @size: size of space we want ot allocate.
 *
 * Return: n allocated.
 */
int *myalloc(int *n, int size)
{
	n = malloc(size * sizeof(int));
	if (!n)
	{
		print_error();
		exit(98);
	}
	init_zero(n, size);
	return (n);
}
/**
 * check_input - checks if cli arguments are all base 10 digits
 *
 * @argv: argument vector.
 *
 * Return: Nothing.
 */
void check_input(char *argv[])
{
	int i;
	char *num1, *num2;

	num1 = argv[1];
	num2 = argv[2];
	for (i = 0; i < _strlen(num1); i++)
		if (num1[i] > '9' || num1[i] < '0')
		{
			print_error();
			exit(98);
		}
	for (i = 0; i < _strlen(num2); i++)
		if (num2[i] > '9' || num2[i] < '0')
		{
			print_error();
			exit(98);
		}
}