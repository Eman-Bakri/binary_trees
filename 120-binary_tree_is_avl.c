#include "binary_trees.h"
#include "limits.h"

int _ifavl(const binary_tree_t *tree, int min_node, int max_node);
size_t _calc_height(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - whether a binary tree is AVL or not.
 * @tree: Pointer to tree root node.
 *
 * Return: 1 if AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_ifavl(tree, INT_MIN, INT_MAX));
}

/**
 * _ifavl - recursive whether a binary tree is AVL or not.
 * @tree: Pointer to tree root node.
 * @min_node: Minimum node been visited value..
 * @max_node: Maximum node been visited value..
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int _ifavl(const binary_tree_t *tree, int min_node, int max_node)
{
	size_t subst;
	size_t _lefthg, _righthg;

	if (tree)
	{
		if (tree->n < min_node || tree->n > max_node)
			return (0);

		_lefthg = _calc_height(tree->left);
		_righthg = _calc_height(tree->right);

		subst = _lefthg > _righthg ? _lefthg - _righthg : _righthg - _lefthg;
		if (subst > 1)
			return (0);

		return (_ifavl(tree->left, min_node, tree->n - 1) &&
			_ifavl(tree->right, tree->n + 1, max_node));
	}
	return (1);
}

/**
 * _calc_height - returns binary tree height.
 * @tree: Pointer to tree root node.
 *
 * Return: return height, otherwise 0.
 */
size_t _calc_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t _leftside = 0;
		size_t _rightside = 0;

		_leftside = tree->left ? 1 + _calc_height(tree->left) : 1;
		_rightside = tree->right ? 1 + _calc_height(tree->right) : 1;

		return ((_leftside > _rightside) ? _leftside : _rightside);
	}
	return (0);
}

