#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function prototypes */
int is_full_node(const binary_tree_t *node, bool *non_full_node);
int enqueue_children(const binary_tree_t *node, binary_tree_t **queue,
int *rear, bool *non_full_node);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
		return (0);

	int front = 0, rear = 0;
	bool non_full_node = false;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		if (!is_full_node(current, &non_full_node))
		{
			free(queue);
			return (0);
		}

		if (!enqueue_children(current, queue, &rear, &non_full_node))
		{
			free(queue);
			return (0);
		}
	}

	free(queue);
	return (1);
}

/**
 * is_full_node - Checks
 * @node: A pointer
 * @non_full_node: A pointer node is encountered
 *
 * Return: 1 if the node is a full node, 0 otherwise
 */
int is_full_node(const binary_tree_t *node, bool *non_full_node)
{
	if (*non_full_node && (node->left || node->right))
		return (0);

	if (!node->left && node->right)
		*non_full_node = true;

	return (1);
}

/**
 * enqueue_children - Enqueues the children of a node
 * @node: A pointer to the node whose children are to be enqueued
 * @queue: A pointer to the queue
 * @rear: A pointer
 * @non_full_node: A pointer
 *
 * Return: 1
 */
int enqueue_children(const binary_tree_t *node, binary_tree_t
**queue, int *rear, bool *non_full_node)
{
	if (node->left)
		queue[(*rear)++] = node->left;
	else if (node->right)
		*non_full_node = true;

	if (node->right)
		queue[(*rear)++] = node->right;
	else if (node->left)
	{
		free(queue);
		return (0);
	}

	return (1);
}
