#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current_node, *parent_node;

    if (tree == NULL)
        return (NULL);

    /* Create a new node */
    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    /* If tree is empty, set the new node as root */
    if (*tree == NULL)
    {
        *tree = new_node;
        return (new_node);
    }

    current_node = *tree;
    while (current_node != NULL)
    {
        parent_node = current_node;

        /* If value is already present, ignore and return NULL */
        if (value == current_node->n)
        {
            free(new_node);
            return (NULL);
        }

        /* Move to the left child if value is less than current node */
        if (value < current_node->n)
            current_node = current_node->left;
        /* Move to the right child if value is greater than current node */
        else
            current_node = current_node->right;
    }

    /* Set the parent of the new node */
    new_node->parent = parent_node;
    
    /* Insert the new node as left or right child of its parent */
    if (value < parent_node->n)
        parent_node->left = new_node;
    else
        parent_node->right = new_node;

    return (new_node);
}

