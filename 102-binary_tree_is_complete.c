#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);
void _queue_pop(levelorder_queue_t **head);
void _queue_free(levelorder_queue_t *head);
void _push_queue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
levelorder_queue_t *_newnode(binary_tree_t *node);

/**
 * binary_tree_is_complete - whether a binary tree complete or not..
 * @tree: Pointer to tree root node.
 *
 * Return: If complete 1, otherwise 0.
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	unsigned char mrk = 0;
	levelorder_queue_t *hd;
	levelorder_queue_t *tl;

	if (!tree)
		return (0);

	hd = _newnode((binary_tree_t *)tree);
	tl = _newnode((binary_tree_t *)tree);

	if (!hd)
		exit(1);

	while (hd != NULL)
	{
		if (hd->node->left != NULL)
		{
			if (mrk == 1)
			{
				_queue_free(hd);
				return (0);
			}
			_push_queue(hd->node->left, hd, &tl);
		}
		else
			mrk = 1;
		if (hd->node->right != NULL)
		{
			if (mrk == 1)
			{
				_queue_free(hd);
				return (0);
			}
			_push_queue(hd->node->right, hd, &tl);
		}
		else
			mrk = 1;
		_queue_pop(&hd);
	}
	return (1);
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
/**
 * _push_queue - Pushes a node to the queue back.
 * @node: binary tree node.
 * @head: Pointer to the queue head.
 * @tail: Pointer to the queue tail.
 *
 */
void _push_queue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node;

	new_node = _newnode(node);
	if (!new_node)
	{
		_queue_free(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
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



