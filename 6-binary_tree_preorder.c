#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: pointer to the function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	// call the function on the current node's value
	func(tree->n);

	// traverse the left subtree
	binary_tree_preorder(tree->left, func);

	// traverse the right subtree
	binary_tree_preorder(tree->right, func);

}
