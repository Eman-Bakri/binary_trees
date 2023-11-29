#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert to the right of a node.
 * @parent: A pointer to the node you want inserting right-child.
 * @value: Value in the new node.
 *
 * Return: a pointer to the new node.
 *          Otherwise: Null.
 *
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/*Invalid Parent*/
	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	/*Allocation failed*/
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);

}
