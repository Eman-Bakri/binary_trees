#include "binary_trees.h"

/**
 * binary_tree_is_root - Whether a node is a root or not.
 * @node: A pointer to the node.
 *
 * Return: If root 1, otherwise 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if ( node == NULL)
		return (0);

	if (node->parent != NULL)
		return (0);
	/*If none of the above satisfied return 1 => root*/
	return (1);
}
