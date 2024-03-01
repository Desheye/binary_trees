#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_avl_helper - ree recursively
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum value a node can take
 * @max: The maximum value a node can take
 *
 * Return: 1 if tree is an AVL tree, otherwise 0
 */
static int binary_tree_is_avl_helper(const binary_tree_t *tree,
int min, int max)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	balance_factor = left_height - right_height;

	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left, min, tree->n - 1) &&
			binary_tree_is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is an AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_helper(tree, INT_MIN, INT_MAX));
}
