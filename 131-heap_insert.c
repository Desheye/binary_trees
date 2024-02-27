#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    int temp;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
        return (*root = new_node);

    parent = binary_tree_last_node(*root);
    if (parent->left == NULL)
    {
        parent->left = new_node;
        new_node->parent = parent;
    }
    else
    {
        parent->right = new_node;
        new_node->parent = parent;
        parent = binary_tree_parent(*root, new_node);
        while (new_node->parent && new_node->n > parent->n)
        {
            temp = parent->n;
            parent->n = new_node->n;
            new_node->n = temp;
            new_node = parent;
            parent = binary_tree_parent(*root, new_node);
        }
    }
    return (new_node);
}

