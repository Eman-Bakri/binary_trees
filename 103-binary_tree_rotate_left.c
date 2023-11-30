#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates binary tree to left side.
 * @tree: Pointer to tree root node.
 *
 * Return: Pointer to the new root node.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *spc;
	binary_tree_t *center;

	if (!tree || tree->right == NULL)
		return (NULL);

	center = tree->right;
	spc = center->left;
	center->left = tree;
	tree->right = spc;

	if (spc != NULL)
		spc->parent = tree;
	spc = tree->parent;
	tree->parent = center;
	center->parent = spc;

	if (spc != NULL)
	{
		if (spc->left == tree)
			spc->left = center;
		else
			spc->right = center;
	}

	return (center);
}
