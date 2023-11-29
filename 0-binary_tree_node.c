#include "binary_trees.h"

/**
 * binary_tree_node - To create new bt node.
 * @parent: A pointer to the created node parent.
 * @value: Value in the new node.
 *
 * Return: a pointer to the new node.
 *          Otherwise: Null.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	/* Allocation failed */
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
