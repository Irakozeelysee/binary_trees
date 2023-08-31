#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Perform a
 * left-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: Pointer to the new root node of the rotated tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *chl, *parent = tree;

	if (!tree)
		return (NULL);
	chl = parent->right;
	if (!chl)
		return (tree);
	if (chl->left)
		chl->left->parent = parent;
	parent->right = chl->left;
	chl->left = parent;
	chl->parent = parent->parent;
	parent->parent = chl;
	if (chl->parent && chl->parent->left == parent)
		chl->parent->left = chl;
	else if (chl->parent)
		chl->parent->right = chl;
	return (chl);
}
