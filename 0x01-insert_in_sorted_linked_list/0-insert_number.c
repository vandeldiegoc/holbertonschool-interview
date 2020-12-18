#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * insert_node - adds a new node at the end of a listint_t list
 * @number: number in node
 * @head: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */


listint_t *insert_node(listint_t **head, int number)
{
listint_t *temp = *head;
listint_t *new_node;
if (head == NULL)
	return(NULL);

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
	return (NULL);

new_node->n = number;
new_node->next = NULL;
if (*head == NULL)
{
	*head = new_node;
	return (new_node);
}

if (new_node->n < temp->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (*head);
	}

while (temp->next != NULL && temp->next->n < number)
	{
	temp = temp->next;
	}
new_node->next = temp->next;
temp->next = new_node;

return (new_node);
}
