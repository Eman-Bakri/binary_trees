#include "binary_trees.h"

/**
 * binary_trees_ancestor - retrns two nodes lowest common ancestor.
 * @first: Pointer to first node.
 * @second: Pointer to second node.
 *
 * Return: return common ancestor, otherwise null.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ances_1;
	binary_tree_t *ances_2;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	ances_1 = first->parent;
	ances_2 = second->parent;

	if (ances_1 == NULL || first == ances_2 || (!ances_1->parent && ances_2))
		return (binary_trees_ancestor(first, ances_2));

	else if (!ances_2 || ances_1 == second || (!ances_2->parent && ances_1))
		return (binary_trees_ancestor(ances_1, second));

	return (binary_trees_ancestor(ances_1, ances_2));
}
