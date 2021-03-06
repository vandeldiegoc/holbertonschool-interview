#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
typedef struct binary_tree_s heap_t;
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_binary_tree(heap_t *root, heap_t *new);
size_t binary_tree_size(heap_t *tree);
heap_t *array_fill(heap_t *root, heap_t **array, heap_t *new);
void add_node(heap_t *root, int n, int *array);
void heapify (heap_t *root, heap_t *new);
void heapify2(heap_t **root, heap_t *new);


#endif /* HEAP_H */