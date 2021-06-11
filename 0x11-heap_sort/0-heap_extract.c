#include "binary_trees.h"

/**
 * tree_height - returns the height of a tree
 * @tree: node to the root of the tree
 * Return: height of the tree
 */
size_t tree_height(heap_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);
	left = tree_height(tree->left);
	right = tree_height(tree->right);
	if (!tree->left && !tree->right)
		return (0);
	return ((left > right ? left + 1 : right + 1));
}

/**
 * binary_tree_preorder - Insert a new node in the tree.
 *
 * @tree: Root of the tree.
 * @h: Height of the tree.
 * @last: Last node of the tree.
 * @level: Level of the tree.
 *
 * Return: Void.
 */

void binary_tree_preorder(heap_t *tree, size_t h, heap_t **last, size_t level)
{
	heap_t *tmp;

	if (tree == NULL)
		return;
	tmp = tree;
	if (tmp)
	{
		if (h == level)
			*last = tmp;
		level++;
		if (tmp->left)
			binary_tree_preorder(tmp->left, h, last, level);
		if (tmp->right)
			binary_tree_preorder(tmp->right, h, last, level);
	}
}

/**
 * heap_extract - Extract the root in a max-heap.
 *
 * @root: Root of the heap.
 *
 * Return: the value of the root.
 */
int heap_extract(heap_t **root)
{
	int value, tmp_value;
	size_t level = 0;
	heap_t *tmp, *last;

	if (root == NULL || *root == NULL)
		return (0);
	tmp = *root;
	value = tmp->n;
	if (tmp->right == NULL && tmp->left == NULL)
	{
		*root = NULL;
		free(tmp);
		return (value);
	}
	binary_tree_preorder(tmp, tree_height(tmp), &last, level);
	while (tmp->left != NULL || tmp->right != NULL)
	{
		if (tmp->right == NULL || tmp->left->n > tmp->right->n)
		{
			tmp_value = tmp->n;
			tmp->n = tmp->left->n;
			tmp->left->n = tmp_value;
			tmp = tmp->left;
		}
		else if (tmp->left == NULL || tmp->right->n > tmp->left->n)
		{
			tmp_value = tmp->n;
			tmp->n = tmp->right->n;
			tmp->right->n = tmp_value;
			tmp = tmp->right;
		}
	}
	tmp->n = last->n;
	if (last->parent->right)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;
	free(last);
	return (value);
}
