#include "search.h"


/**
 * print_val - search through list, print value
 * @prevskip:  pointer to prev node
 * @expskip: pointer to destination node
 * @value: value to search
 *
 * Return: pointer with node valjue or NULL
 */
skiplist_t *print_val(skiplist_t *prevskip, skiplist_t *expskip, int value)
{

	printf("Value found between indexes [%li] and [%li]\n",
			prevskip->index, expskip->index);
	while (prevskip != expskip->next)
	{
		printf("Value checked at index [%li] = [%d]\n",
			prevskip->index, prevskip->n);
		if (prevskip->n == value)
			return (prevskip);
		prevskip = prevskip->next;
	}
	return (NULL);
}


/**
 * linear_skip - searches for a value in sorted list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 * Return: Always EXIT_SUCCESS
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prevskip, *nextskip;

	if (!list)
		return (NULL);
	nextskip = list;
	while (nextskip)
	{
		prevskip = nextskip;
		if (nextskip->express)
			nextskip = nextskip->express;
		else

		{
			while (nextskip->next)
				nextskip = nextskip->next;
			break;
		}
		printf("Value checked at index [%lu] = [%i]\n",
			nextskip->index, nextskip->n);
		if (nextskip->n >= value)
			return (print_val(prevskip, nextskip, value));
	}
	return (print_val(prevskip, nextskip, value));
}
