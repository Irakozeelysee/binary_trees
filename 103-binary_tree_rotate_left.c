#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_rotate_left - Perform a
 * left-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 * Return: Pointer to the new root node of the rotated tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);
	if (!tree->right)
		return (tree);
	binary_tree_t *new_root = tree->right;
	binary_tree_t *temp_subtree = new_root->left;

	new_root->left = tree;

	tree->right = temp_subtree;
	if (temp_subtree)
		temp_subtree->parent = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	return (new_root);
}
