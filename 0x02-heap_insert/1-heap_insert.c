#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * heap_insert - insert a node in a binary tree using max-heap.
 *
 * @root: root of the node.
 * @value: value n to put for the node.
 *
 * Return: node pointer to the new node, NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (!root)
		return (NULL);
	new = malloc(sizeof(heap_t));
	if (!new)
		return (NULL);
	new->parent = NULL;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	if ((*root) == NULL)
	{
		*root = new;
		return (new);
	}

	array_binary_tree(*root, new);
	while (new->parent && new->n > new->parent->n)
	{
		heapify2(root, new);
	}
	return (new);
}
/**
 * heapify2 - swap nodes.
 *
 * @root: parent of the node.
 * @new: address of the new node
 *
 * Return: node pointer to the new node, NULL on failure.
 */
void heapify2(heap_t **root, heap_t *new)
{
	heap_t *parent = new->parent, *otherchild;

	if (parent->left && parent->left != new)
		parent->left->parent = new;
	if (parent->right && parent->right != new)
		parent->right->parent = new;

	if (new->left)
		new->left->parent = parent;
	if (new->right)
		new->right->parent = parent;

	if (parent->left == new)
	{
		otherchild = parent->right;
		parent->left = new->left;
		parent->right = new->right;
		new->right = otherchild;
		new->left = parent;
	}

	if (parent->right == new)
	{
		otherchild = parent->left;
		parent->left = new->left;
		parent->right = new->right;
		new->left = otherchild;
		new->right = parent;
	}

	new->parent = parent->parent;
	if (parent->parent && parent->parent->left == parent)
		parent->parent->left = new;
	if (parent->parent && parent->parent->right == parent)
		parent->parent->right = new;
	parent->parent = new;
	if (!new->parent)
		*root = new;
}
/**
 * array_binary_tree - does the array
 *
 * @root: root of the heap.
 * @new: the new node.
 *
 * Return: new node.
 */
heap_t *array_binary_tree(heap_t *root, heap_t *new)
{
	heap_t *array[1024];

	if (!root)
		return (NULL);
	return (array_fill(root, array, new));
}
/**
 * array_fill - fills array, and adds a node to the end.
 *
 * @root: root of the heap.
 * @array: array to put in the pointers of the heap.
 * @new: the new node.
 *
 * Return: new node.
 */
heap_t *array_fill(heap_t *root, heap_t **array, heap_t *new)
{
	size_t i;

	i = 0;
	array[0] = root;
	while (array[i])
	{
		if (array[i]->left)
			array[(2 * i) + 1] = array[i]->left;
		else if (!(array[i])->left)
		{
			array[(2 * i) + 1] = new;
			array[i]->left = new;
			new->parent = array[i];
			return (new);
		}
		if (array[i]->right)
			array[(2 * i) + 2] = array[i]->right;
		else if (!(array[i])->right)
		{
			array[(2 * i) + 2] = new;
			array[i]->right = new;
			new->parent = array[i];
			return (new);
		}
		i++;
	}
	i = 0;
	while (array[i])
	{
		printf("| %d ", array[i]->n);
		i++;
	}
	printf("|\n");
	return (new);
}

/**
 * binary_tree_size - size of a tree.
 *
 * @tree: root.
 *
 * Return: size.
 */
size_t binary_tree_size(heap_t *tree)
{
	if (!tree)
		return (0);
	else
		return (binary_tree_size(tree->right) + binary_tree_size(tree->left) + 1);
}
