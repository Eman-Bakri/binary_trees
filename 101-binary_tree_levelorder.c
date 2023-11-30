#include "binary_trees.h"

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void _queue_pop(levelorder_queue_t **head);
void _push_print(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
levelorder_queue_t *_newnode(binary_tree_t *node);
void _queue_free(levelorder_queue_t *head);


/**
 * binary_tree_levelorder - traverse binary tree with level-order.
 * @tree: Pointer to tree root node.
 * @func: Pointer to call a function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *hd;
	levelorder_queue_t *tl;

	if (tree == NULL || func == NULL)
		return;

	hd = _newnode((binary_tree_t *)tree);
	tl = _newnode((binary_tree_t *)tree);

	if (!hd)
		return;

	while (hd != NULL)
	{
		_push_print(hd->node, hd, &tl, func);
		_queue_pop(&hd);
	}
}

/**
 * pop - Pops the queue head.
 * @head: Pointer to the queue head.
 */
void _queue_pop(levelorder_queue_t **head)
{
	levelorder_queue_t *spc;

	spc = (*head)->next;
	free(*head);
	*head = spc;
}

/**
 * _push_print - pushes the children o a bt node into queue.
 * @node: The binary tree node.
 * @head: Pointer to the queue head.
 * @tail: Pointer to the queue tail.
 * @func: Pointer to call the function.
 *
 */
void _push_print(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_node;

	func(node->n);
	if (node->left != NULL)
	{
		new_node = _newnode(node->left);
		if (!new_node)
		{
			_queue_free(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right != NULL)
	{
		new_node = _newnode(node->right);
		if (!new_node)
		{
			_queue_free(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}
/**
 * _newnode - add a new node.
 * @node: The node in binary tree.
 *
 * Return: Pointer to new node, otherwise null.
 */
levelorder_queue_t *_newnode(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));

	if (!new_node)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * _queue_free - free queue.
 * @head: Pointer to queue head.
 */
void _queue_free(levelorder_queue_t *head)
{
	levelorder_queue_t *spc;

	while (head != NULL)
	{
		spc = head->next;
		free(head);
		head = spc;
	}
}

