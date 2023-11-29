#include "binary_trees.h"

/**
 * binary_tree_uncle - returns the node uncle.
 * @node: Pointer to the node.
 *
 * Return: Pointer to uncle node, or NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!(node->parent->parent) || !(node->parent))
		return (NULL);

	if (node == NULL)
		return (NULL);

	if ((node->parent->parent->left) == (node->parent))
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}
