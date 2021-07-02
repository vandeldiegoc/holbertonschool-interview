#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list: 
 * @list: list to be modify
 * @str: string to copy onto the new node
 * Return: Returns: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
List *new_node, *tmp;

if (str == NULL)
	return (NULL);

new_node = malloc(sizeof(list));

if (new_node == NULL)
	return (NULL);



new_node->str = strdup(str);

if (*list == NULL)
{
	new_node->next = new_node->prev = new_node;
	*list = new_node;
	return (new_node);
}

tmp = (*list)->prev;
tmp->next = new_node;

new_node->next = *list;
(*list)->prev = new_node;

new_node->prev = tmp;
tmp->next = new_node;

return (*list);
}


/**
 * add_node_end - Add a new node to the end of a double circular linked list: 
 * @list: list to be modify
 * @str: string to copy onto the new node
 * Return: Returns: Address of the new node, or NULL on failure
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
