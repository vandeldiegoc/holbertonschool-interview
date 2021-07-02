#include "list.h"
/**
 * add_node_end - Add a new node to the end of a double circular linked list:
 * @list: list to be modify
 * @str: string to copy onto the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *last_node;

	if (!list)
		return (NULL);

	if (!str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last_node = (*list)->prev;

	last_node->next = new_node;
	new_node->next = *list;
	new_node->prev = last_node;
	(*list)->prev = new_node;
	return (new_node);
}

/**
 * @list: list to be modify
 * @str: string to copy onto the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *tmp;

	if (!list)
		return (NULL);
	if (!str)
		return (NULL);
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	tmp = (*list)->prev;

	new_node->next = (*list);
	new_node->prev = tmp;
	(*list)->prev = tmp->next = new_node;
	*list = new_node;

	return (new_node);
}
