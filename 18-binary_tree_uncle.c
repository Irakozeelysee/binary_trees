#include "binary_trees.h"


/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node
 *         NULL if node is NULL or parent is NULL
 *         if node has no sibling NULL is returned
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);

	return (NULL); /* node is not a child of its parent */
}


/**
 * binary_tree_uncle - finds the uncle of a node
 * (so i can get some money from him)
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node
 *         NULL if not found
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->parent == NULL)
		return (NULL); /* cannot be an uncle without a parent */

	return (binary_tree_sibling(node->parent));
}
