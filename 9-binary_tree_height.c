#include "binary_trees.h"

/**
 * binary_tree_height - Calculate the binary tree height.
 * @tree: Pointer to tree root node.
 *
 * Return: return height, otherwise Null.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_ht = 0;
	size_t left_ht = 0;

	if (tree != NULL)
	{
		right_ht = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		left_ht = tree->left ? 1 + binary_tree_height(tree->left) : 0;

		return ((left_ht > right_ht) ? left_ht : right_ht);
	}
	
	return (0);
}
