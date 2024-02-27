#include "binary_trees.h"
#include <stdio.h>

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: A double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *tmp;
	int value;
	size_t size, height, i;
	heap_t **array;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	height = binary_tree_height(*root);
	size = binary_tree_size(*root);
	array = malloc(sizeof(heap_t *) * size);
	if (array == NULL)
		return (0);

	for (i = 0; i < size; i++)
		array[i] = NULL;
	i = 0;
	array[i] = *root;
	while (array[i] != NULL)
	{
		if (array[i]->left != NULL)
		{
			array[i * 2 + 1] = array[i]->left;
			if (array[i * 2 + 1]->n > array[i]->n)
				tmp = array[i];
		}
		if (array[i]->right != NULL)
		{
			array[i * 2 + 2] = array[i]->right;
			if (array[i * 2 + 2]->n > array[i]->n)
				tmp = array[i];
		}
		i++;
	}
	last_node = array[i - 1];
	free(*root);
	*root = last_node;

	if (tmp == NULL)
		return (value);
	return (value);
}

