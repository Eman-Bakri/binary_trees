#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates binary tree to right side.
 * @tree: Pointer to tree root node.
 *
 * Return: Pointer to the new root node, post rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *spc;
	binary_tree_t *center;

	if (!tree || tree->left == NULL)
		return (NULL);

	center = tree->left;
	spc = center->right;
	center->right = tree;
	tree->left = spc;

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
