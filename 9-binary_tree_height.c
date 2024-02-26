#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_left, height_right;

    if (tree == NULL)
        return (0);

    /* Recursively calculate the height of the left subtree */
    height_left = binary_tree_height(tree->left);

    /* Recursively calculate the height of the right subtree */
    height_right = binary_tree_height(tree->right);

    /* Return the maximum height of the left and right subtrees, plus 1 for the current node */
    return (1 + (height_left > height_right ? height_left : height_right));
}

