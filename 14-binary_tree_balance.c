#include "binary_trees.h"

/**
 * binary_tree_height - Calculate the binary tree height.
 * @tree: Pointer to tree root node.
 *
 * Return: return height, otherwise Null.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{

	if (tree)
	{
		size_t right_ht = 0;
		size_t left_ht = 0;

		right_ht = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		left_ht = tree->left ? 1 + binary_tree_height(tree->left) : 1;

		return ((left_ht > right_ht) ? left_ht : right_ht);
	}

	return (0);
}


/**
 * binary_tree_balance - calculates the tree balance factor.
 * @tree: Pointer to the tree root node.
 *
 * Return: return balance factor, otherwise 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree != NULL)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}
