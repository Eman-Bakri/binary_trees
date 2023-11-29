#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse binary tree with in-order.
 * @tree: Pointer to the tree root node.
 * @func: Pointer to call a function.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (func && tree != NULL)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
