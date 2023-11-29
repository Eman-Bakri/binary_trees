#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse a binary tree with post-order.
 * @tree: Pointer to the tree root node.
 * @func: Pointer to call a function.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (func && tree != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
