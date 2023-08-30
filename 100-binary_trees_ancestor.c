#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest
 * common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor
 * or NULL if not found
 *
 */

binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	binary_tree_t *ancestor = (binary_tree_t *)first;

	while (ancestor != NULL)
	{
		if (binary_tree_is_ancestor(ancestor, second))
			return (ancestor);
		ancestor = ancestor->parent;
	}
	return (NULL);
}

/**
 * binary_tree_is_ancestor - Checks if 
 * a node is an ancestor of another node
 * @ancestor: Pointer to the potential ancestor node
 * @node: Pointer to the target node
 * Return: 1 if ancestor is an ancestor of node, 0 otherwise
 */
int binary_tree_is_ancestor(const binary_tree_t *ancestor, const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (ancestor == node)
		return (1);
	return (binary_tree_is_ancestor(ancestor, node->parent));
}
