#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_complete - Check if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_is_complete_recursive(tree, 0, binary_tree_size(tree)));
}

/**
 * binary_tree_size - Calculate the size of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: Size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete_recursive - Check if a binary
 * tree is complete recursively.
 * @tree: Pointer to the root node of the tree.
 * @index: Index of the current node.
 * @nodes: Total number of nodes in the tree.
 * Return: 1 if complete, 0 otherwise.
 */
int binary_tree_is_complete_recursive(const binary_tree_t *tree,
					size_t index, size_t nodes)
{
	if (!tree)
		return (0);
	if (index >= nodes)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->right && !tree->left)
		return (0);
	if (tree->left && !tree->right)
		return (binary_tree_is_complete_recursive(tree->left, index * 2 + 1, nodes));

	return (binary_tree_is_complete_recursive(tree->left, index * 2 + 1, nodes) &&
			binary_tree_is_complete_recursive(tree->right, 2 * index + 2, nodes));
}
