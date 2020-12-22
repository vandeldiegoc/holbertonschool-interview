#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: pointer to the new node
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *head;
head = malloc(sizeof(binary_tree_t));
if (head == NULL)
return (NULL);

head->n = value;
head->left = NULL;
head->right = NULL;

if (parent == NULL)
head->parent = NULL;
else
head->parent = parent;

return (head);
}
