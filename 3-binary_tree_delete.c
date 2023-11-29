#include "binary_trees.h"

/**
 * binary_tree_delete - To delete binary tree.
 * @tree: A pointer to the tree root node.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL) 
	{
		return; /*Nothing to delete*/
	}

	/*Delete left and right subtrees recursively */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/*Delete a specific node*/
	free(tree);

}
