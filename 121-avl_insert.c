#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree for inserting
 *        the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    /* If tree is empty, set the new node as root */
    if (*tree == NULL)
    {
       /* *tree = binary_tree_node(NULL, value);*/
       *tree = avl_node(NULL, value);

        if (*tree == NULL)
            return (NULL);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
        if ((*tree)->left == NULL)
            return (NULL);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
        if ((*tree)->right == NULL)
            return (NULL);
    }
    else
    {
        /* Value already exists, return NULL */
        return (NULL);
    }

    /* Update the height and balance factor of the current node */
    (*tree)->height = 1 + max(binary_tree_height((*tree)->left), binary_tree_height((*tree)->right));
    (*tree)->balance = binary_tree_balance(*tree);

    /* Perform rotations if necessary to balance the tree */
    if ((*tree)->balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);
    if ((*tree)->balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);
    if ((*tree)->balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }
    if ((*tree)->balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }

    return (*tree);
}

