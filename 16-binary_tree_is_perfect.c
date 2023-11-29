#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree);
int _recursive_perfect(const binary_tree_t *tree,
		size_t _depthleaf, size_t node_level);
size_t _depth_node(const binary_tree_t *tree);
const binary_tree_t *_leaf_return(const binary_tree_t *tree);
unsigned char _leaf_node(const binary_tree_t *node);

/**
 * binary_tree_is_perfect - whether a binary tree is perfect or not.
 * @tree: Pointer to the tree root node.
 *
 * Return: If perfect 1, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	
	return (_recursive_perfect(tree, _depth_node(_leaf_return(tree)), 0));
}

/**
 * _recursive_perfect - recursive version of perfect.
 * @tree: Pointer to tree root node.
 * @_depthleaf: One leaf depth.
 * @node_level: current node level.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int _recursive_perfect(const binary_tree_t *tree,
		size_t _depthleaf, size_t node_level)
{
	if (_leaf_node(tree))
		return (node_level == _depthleaf ? 1 : 0);

	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (_recursive_perfect(tree->left, _depthleaf, node_level + 1) &&
		_recursive_perfect(tree->right, _depthleaf, node_level + 1));
}

/**
 * _depth_node - find node depth.
 * @tree: Pointer to node.
 *
 * Return: Node depth.
 */
size_t _depth_node(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + _depth_node(tree->parent) : 0);
}

/**
 * _leaf_return - return a leaf.
 * @tree: Pointer to tree root node.
 *
 * Return: Pointer to the leaf found first.
 */
const binary_tree_t *_leaf_return(const binary_tree_t *tree)
{
	if (_leaf_node(tree) == 1)
		return (tree);

	return (tree->left ? _leaf_return(tree->left) : _leaf_return(tree->right));
}

/**
 * _leaf_node - is node a leaf.
 * @node: Pointer to the node.
 *
 * Return: If leaf, 1, otherwise, 0.
 */
unsigned char _leaf_node(const binary_tree_t *node)
{
	return ((node->right == NULL && node->left == NULL) ? 1 : 0);
}
