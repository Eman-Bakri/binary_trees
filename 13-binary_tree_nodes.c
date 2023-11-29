#include "binary_trees.h"

/**
 * binary_tree_nodes - Node count with minimum one child.
 * @tree: Pointer to tree root node.
 *
 * Return: return node count, otherwise 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t num_nodes = 0;

	if (tree != NULL)
	{
		num_nodes += (tree->right || tree->left) ? 1 : 0;
		num_nodes += binary_tree_nodes(tree->right);
		num_nodes += binary_tree_nodes(tree->left);
	}
	return (num_nodes);
}
