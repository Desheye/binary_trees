#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}

/**
 * binary_tree_is_avl_helper - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 * @min: The minimum value a node in the tree can have
 * @max: The maximum value a node in the tree can have
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	size_t left_height, right_height;
	int balance_factor;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		balance_factor = left_height - right_height;
	else
		balance_factor = right_height - left_height;

	if (balance_factor > 1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left, min, tree->n - 1) &&
		binary_tree_is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_helper(tree, INT_MIN, INT_MAX));
}

