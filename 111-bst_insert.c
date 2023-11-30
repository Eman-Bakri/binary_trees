#include "binary_trees.h"

/**
 * bst_insert - insert new in BST.
 * @tree: Pointer to the BST root node.
 * @value: Value to add.
 *
 * Return: Pointer to the new value node, otherwise NULL.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *spc, *new_node;

	if (tree)
	{
		spc = *tree;

		if (!spc)
		{
			new_node = binary_tree_node(spc, value);

			if (!new_node)
				return (NULL);

			return (*tree = new_node);
		}

		/*left subtree insertion*/
		if (value < spc->n)
		{
			if (spc->left != NULL)
				return (bst_insert(&spc->left, value));

			new_node = binary_tree_node(spc, value);

			if (!new_node)
				return (NULL);

			return (spc->left = new_node);
		}
		/*right subtree insertion*/
		if (value > spc->n)
		{
			if (spc->right != NULL)
				return (bst_insert(&spc->right, value));

			new_node = binary_tree_node(spc, value);

			if (!new_node)
				return (NULL);

			return (spc->right = new_node);
		}
	}
	return (NULL);
}
