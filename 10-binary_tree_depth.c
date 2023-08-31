#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in binary tree
 * @tree: pointer to the node to mesure
 * Return: the depth of the node, 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *current;

	if (tree == NULL)
		return (0);

	current = tree;

	while (current->parent != NULL)
	{
		depth++;
		current = current->parent;
	}

	return (depth);
}
