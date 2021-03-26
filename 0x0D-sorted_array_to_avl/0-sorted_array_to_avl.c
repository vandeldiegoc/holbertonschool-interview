#include "binary_trees.h"

/**
 * sorted_array_to_avl - Sort an array into an AVL tree
 *
 * @array: pointer to the first element of the array
 * @size: the number of elements in the array
 * Return: the inserted node or null if it fails
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);
	return (avl_insert_node(array, 0, size - 1, NULL));
}

/**
 * avl_insert_node - Function to insert node
 *
 * @ar: array to be printed
 * @f: first array's element
 * @l: last array's element
 * @r: root of the tree
 * Return: null if fail or null insertion
 */

avl_t *avl_insert_node(int *ar, size_t f, size_t l, avl_t *r)
{
	size_t half;
	avl_t *new;

	if (f > l)
		return (NULL);
	half = (f + l) / 2;
	new = create_node(r, ar[half]);
	if (!new)
		return (NULL);
	if (half != f)
		new->left = avl_insert_node(ar, f, half - 1, new);
	if (half != l)
		new->right = avl_insert_node(ar, half + 1, l, new);
	return (new);
}

/**
 * create_node - Function to create a new node
 *
 * @r: parent root
 * @dt: data to be inseted
 * Return: nnull if fail or null insertion
 */

avl_t *create_node(avl_t *r, size_t dt)
{
	avl_t *n_Node;

	n_Node = malloc(sizeof(avl_t));
	if (!n_Node)
		return (NULL);
	n_Node->n = dt;
	n_Node->left = NULL;
	n_Node->right = NULL;
	n_Node->parent = r;
	return (n_Node);
}
