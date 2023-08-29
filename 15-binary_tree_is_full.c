#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is full, 0 otherwise or if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* if both children are null, it is a leaf i.e it is full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* if one child is null and the other is not null it is not full */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* recursively check left and right subtrees */
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
