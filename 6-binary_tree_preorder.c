#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse binary tree in pre-order.
 * @tree: Pointer to the tree root node.
 * @func: Pointer to a call a function.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (func && tree != NULL)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
