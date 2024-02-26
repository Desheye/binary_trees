#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is NULL or not perfect - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int height = 0, nodes = 0, max_nodes = 0;

    if (tree == NULL)
        return (0);

    height = binary_tree_height(tree);
    nodes = binary_tree_size(tree);
    max_nodes = (1 << (height + 1)) - 1;

    return (nodes == max_nodes);
}

