#ifndef _BINARY_TREES_
#define _BINARY_TREES_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *tree);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *avl_insert_node(int *ar, size_t f, size_t l, avl_t *r);
avl_t *create_node(avl_t *r, size_t dt);

#endif /*_BINARY_TREES_*/
