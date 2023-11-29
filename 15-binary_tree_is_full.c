#include "binary_trees.h"

int _recursive_fully(const binary_tree_t *tree);
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

	return (_recursive_fully(tree));

}
/**
 * _recursive_fully - recursive version.
 * @tree: Pointer to tree root node.
 *
 * Return: If full 1, otherwise 0.
 */
int _recursive_fully(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    _recursive_fully(tree->left) == 0 ||
		    _recursive_fully(tree->right) == 0)
			return (0);
	}
	return (1);
}
