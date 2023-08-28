#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a new node as the right child of a
 * another node
 * if the parent already has a right child the new node must take it's place
 * and the old right child must be set as the right child of the new node
 * @parent: pointer to the node t insert the right child in
 * @value: the value to store in the new node
 * Return: pointer to the new node
 *        NULL on failure or if the parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
