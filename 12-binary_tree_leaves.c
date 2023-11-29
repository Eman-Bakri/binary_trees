#include "binary_trees.h"

/**
 * binary_tree_leaves - returns the leaves count.
 * @tree: Pointer to tree root node.
 *
 * Return: no. of leaves.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t num_leaves = 0;

	if (tree != NULL)
	{
		num_leaves += (!tree->right && !tree->left) ? 1 : 0;
		num_leaves += binary_tree_leaves(tree->right);
		num_leaves += binary_tree_leaves(tree->left);
	}
	return (num_leaves);
}
