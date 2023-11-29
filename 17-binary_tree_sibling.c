#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds node sibling.
 * @node: Pointer to the node.
 *
 * Return: Pointer to the sibling, othewise NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node->parent == NULL)
		return (NULL);

	if (node == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
