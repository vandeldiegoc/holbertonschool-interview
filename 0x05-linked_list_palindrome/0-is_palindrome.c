#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * verify_palindrome - checks if it's a palindrome
 * @left: pointer of left node
 * @right: double pointer of right node
 * Return: 0 if it's not a palindrome, pal otherwise
 */
int verify_palindrome(listint_t **left, listint_t *right)
{
	int palindrome;

	if (right == NULL)
		return (1);

	palindrome = verify_palindrome(left, right->next);

	if (palindrome == 0)
		return (0);

	palindrome = (right->n == (*left)->n);
	*left = (*left)->next;

	return (palindrome);
}
/**
 * is_palindrome -  checks if a singly linked list is a palindrome.
 * @head: double pinter to head node
 * Return: A palindrome
 */
int is_palindrome(listint_t **head)
{
	int palindrome;
palindrome = verify_palindrome(head, *head);
	return (palindrome);
}
