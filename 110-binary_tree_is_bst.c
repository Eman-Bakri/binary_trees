#include "binary_trees.h"
#include "limits.h"

int _rec_is_bst(const binary_tree_t *tree, int min_node, int max_node);

/**
 * binary_tree_is_bst - whether a binary tree is BST or not.
 * @tree: Pointer to tree root node.
 *
 * Return: 1 if tree BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_rec_is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * _rec_is_bst - recursive whether a binary tree is BST or not.
 * @tree: Pointer to tree root node.
 * @min_node: Minimum node been visited value.
 * @max_node: Maximum node been visited value.
 *
 * Return: If tree is BST 1, otherwise 0.
 */
int _rec_is_bst(const binary_tree_t *tree, int min_node, int max_node)
{
	if (tree)
	{
		if (tree->n < min_node || tree->n > max_node)
			return (0);

		return (_rec_is_bst(tree->left, min_node, tree->n - 1) &&
			_rec_is_bst(tree->right, tree->n + 1, max_node));
	}
	return (1);
}
