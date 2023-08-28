#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * If the parent has a left child, the new node must take it's place and the
 * old left child must be set as the left child of the new node
 * @parent: the node to insert the new node as the left child in
 * @value: the value of the new node
 * Return: a pointer to the created node
 *          NULL on failure or if the parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
