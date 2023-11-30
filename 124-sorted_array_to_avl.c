#include "binary_trees.h"

void _tree_new(avl_t **node, int *array, size_t arrsize, int flag);

/**
 * sorted_array_to_avl - new root node & tree.
 * @array: Ints array.
 * @size: Array size.
 * Return: Pointer to root.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t center;
	avl_t *_rootnode;

	_rootnode = NULL;

	if (size == 0)
		return (NULL);

	center = (size / 2);

	center = (size % 2 == 0) ? center - 1 : center;

	_rootnode = binary_tree_node(_rootnode, array[center]);

	_tree_new(&_rootnode, array, center, 1);
	_tree_new(&_rootnode, array + center + 1, (size - 1 - center), 2);

	return (_rootnode);
}

/**
 * _tree_new - new tree
 *
 * @node: Pointer node.
 * @array: ints array.
 * @arrsize: Array size.
 * @flag: 1 for left, 2 for right.
 *
 */
void _tree_new(avl_t **node, int *array, size_t arrsize, int flag)
{
	size_t center;

	if (arrsize == 0)
		return;

	center = (arrsize / 2);
	center = (arrsize % 2 == 0) ? center - 1 : center;

	if (flag == 1)
	{
		(*node)->left = binary_tree_node(*node, array[center]);
		_tree_new(&((*node)->left), array, center, 1);
		_tree_new(&((*node)->left), array + center + 1, (arrsize - 1 - center), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[center]);
		_tree_new(&((*node)->right), array, center, 1);
		_tree_new(&((*node)->right), array + center + 1, (arrsize - 1 - center), 2);
	}
}
