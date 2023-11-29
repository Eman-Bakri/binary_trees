#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Whether a node is a leaf or not.
 * @node: A pointer to the node.
 *
 * Return: if leaf 1, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node->right != NULL || node->left != NULL || node == NULL)
		return (0);

	/*If none of the above satisfied return 1 => leaf*/
	else
		return (1);
}
