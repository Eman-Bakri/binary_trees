#include "binary_trees.h"

/**
 * binary_tree_is_full - If the binary tree full or not.
 * @tree: Pointer to tree root node.
 *
 * Return: If full 1, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	else
		if ((tree->left == NULL && tree->right != NULL) ||
		    (tree->left != NULL && tree->right == NULL) ||
		    binary_tree_is_full(tree->left) == 0 ||
		    binary_tree_is_full(tree->right) == 0)
				return (0);

	return (1);
}
