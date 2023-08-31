#include "binary_trees.h"
#include <stddef.h>
#include <limits.h>

/**
 * binary_tree_is_bst - Check if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst_recursive(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_recursive - Check if
 * a binary tree is a valid BST recursively.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum allowed value for a node.
 * @max: Maximum allowed value for a node.
 * Return: 1 if valid BST, 0 otherwise.
 */
int is_bst_recursive(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst_recursive(tree->left, min, tree->n) &&
			is_bst_recursive(tree->right, tree->n, max));
}
