#include "binary_trees.h"

/**
 * binary_tree_size - Calculate the binary tree size.
 * @tree: Pointer to tree root node.
 *
 * Return: The tree size.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 0;

	if (tree != NULL)
	{
		tree_size += 1;
		tree_size += binary_tree_size(tree->right); /*Recursively*/
		tree_size += binary_tree_size(tree->left); /*Recursively*/
	}
	return (tree_size);
}
