#include "binary_trees.h"

/* Declare function prototypes */
static bst_t *create_bst_node(int value);
static bst_t *bst_insert_recursive(bst_t *tree, int value);

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = create_bst_node(value);
		return (*tree);
	}

	return (bst_insert_recursive(*tree, value));
}

/**
 * create_bst_node - Creates a new node for a binary search tree
 * @value: The value to store in the node
 *
 * Return: A pointer to the created node, or NULL on failure
 */
static bst_t *create_bst_node(int value)
{
	bst_t *new_node = malloc(sizeof(bst_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * bst_insert_recursive - Inserts a value recursively into a binary search tree
 * @tree: A pointer to the root node of the BST
 * @value: The value to insert
 *
 * Return: A pointer to the created node, or NULL on failure
 */
static bst_t *bst_insert_recursive(bst_t *tree, int value)
{
	if (tree == NULL)
		return (create_bst_node(value));

	if (value == tree->n)
		return (NULL); /* Value already exists */

	if (value < tree->n)
		tree->left = bst_insert_recursive(tree->left, value);
	else
		tree->right = bst_insert_recursive(tree->right, value);

	return (tree);
}
