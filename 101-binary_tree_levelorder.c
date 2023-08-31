#include "binary_trees.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - Performs
 * level-order traversal on a binary tree.
 * @tree: A pointer to the root node
 * of the tree to traverse.
 * @func: A pointer to a function
 * to call for each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree,
			    void (*func)(int))
{
	int front = 0;
	int rear = 0;

	if (tree == NULL || func == NULL)
		return;

	binary_tree_t *queue[1024];
	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		binary_tree_t *node = queue[front++];
		func(node->n);
		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}
}
