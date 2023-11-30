#include "binary_trees.h"

/**
 * array_to_bst - create BST from array.
 * @array: Pointer to the array first element.
 * @size: Array number of elements.
 *
 * Return: Pointer to the root node, otherwise NULL.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t a, b;
	bst_t *Mytree = NULL;

	if (!array)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}

		if (b == a)
		{
			if (bst_insert(&Mytree, array[a]) == NULL)
				return (NULL);
		}
	}

	return (Mytree);
}
