#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 * Description: if the tree is not NULL, the function recursively
 * deletes the left and right entire subtree
 * and then deletes current node
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/*delete the left subtree */
	binary_tree_delete(tree->left);

	/*delete the right subtree */
	binary_tree_delete(tree->right);

	/*delete the current node */
	free(tree);
}
