#include "binary_trees.h"

/**
 * bst_search - searching BST for a value.
 * @tree: Pointer to BST root node.
 * @value: Value to search for.
 *
 * Return: Pointer to the node has the value, otherwise NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);

		if (tree->n < value)
			return (bst_search(tree->right, value));

		return (bst_search(tree->left, value));
	}
	return (NULL);
}
