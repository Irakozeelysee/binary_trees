#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t index;

	bst_t *tree_root = NULL;

	for (index = 0; index < size; index++)
	{
		if (bst_insert(&tree_root, array[index]) == NULL)
		{
			return (NULL);
		}
	}
	return (tree_root);
}