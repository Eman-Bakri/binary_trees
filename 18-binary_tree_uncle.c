#include "binary_trees.h"

/**
 * binary_tree_uncle - returns the node uncle.
 * @node: Pointer to the node.
 *
 * Return: Pointer to uncle node, or NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{

	if (!node)
		return (NULL);

	if (!(node->parent) || !(node->parent->parent))
		return (NULL);


	if ((node->parent->parent->right) == (node->parent))
		return (node->parent->parent->left);
	else
		return (node->parent->parent->right);
}
