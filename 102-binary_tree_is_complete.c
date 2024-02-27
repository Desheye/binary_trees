#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    /* Initialize a queue for level-order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024); /* Assume a maximum size of 1024 */
    if (queue == NULL)
        return (0);

    int front = 0, rear = 0;
    bool non_full_node = false; /* Flag to mark if we've encountered a non-full node */
    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *current = queue[front++];

        /* If we've encountered a non-full node before, and the current node is not a leaf, the tree is not complete */
        if (non_full_node && (current->left != NULL || current->right != NULL))
        {
            free(queue);
            return (0);
        }

        /* If current node has a left child, enqueue it */
        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }
        /* If current node has no left child, mark it as non-full */
        else
        {
            non_full_node = true;
        }

        /* If current node has a right child, enqueue it */
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
        /* If current node has no right child, but the left child is present, the tree is not complete */
        else if (current->left != NULL)
        {
            free(queue);
            return (0);
        }
    }

    free(queue);
    return (1);
}

