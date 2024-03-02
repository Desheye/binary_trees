#include "binary_trees.h"

/**
 * avl_insert_recursive - Inserts a value in an AVL Tree recursively
 * @tree: A double pointer to the root node of the AVL tree for inserting
 *        the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t **tree, int value)
{
if (tree == NULL)
return (NULL);

avl_t *new_node;

/* If tree is empty, set the new node as root */
if (*tree == NULL)
{
new_node = avl_node(NULL, value);
if (new_node == NULL)
return (NULL);

*tree = new_node;
return (new_node);
}

if (value < (*tree)->n)
{
(*tree)->left = avl_insert_recursive(&((*tree)->left), value);
if ((*tree)->left == NULL)
return (NULL);
}
else if (value > (*tree)->n)
{
(*tree)->right = avl_insert_recursive(&((*tree)->right), value);
if ((*tree)->right == NULL)
return (NULL);
}
else
{
/* Value already exists, return NULL */
return (NULL);
}

update_height_and_balance(tree);

return (balance_tree(tree, value));
}

/**
 * update_height_and_balance - Update the height and balance factor of a node
 * @node: The node to update
 */
void update_height_and_balance(avl_t **node)
{
if (node == NULL || *node == NULL)
return;

(*node)->height = 1 + MAX(binary_tree_height((*node)->left),
binary_tree_height((*node)->right));
(*node)->balance = binary_tree_balance(*node);
}

/**
 * balance_tree - Balance the AVL tree if necessary
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value of the node that was just inserted
 *
 * Return: A pointer to the new root node of the balanced AVL tree
 */
avl_t *balance_tree(avl_t **tree, int value)
{
if (*tree == NULL)
return (NULL);

if ((*tree)->balance > 1 && value < (*tree)->left->n)
return (binary_tree_rotate_right(*tree));
if ((*tree)->balance < -1 && value > (*tree)->right->n)
return (binary_tree_rotate_left(*tree));
if ((*tree)->balance > 1 && value > (*tree)->left->n)
{
(*tree)->left = binary_tree_rotate_left((*tree)->left);
return (binary_tree_rotate_right(*tree));
}
if ((*tree)->balance < -1 && value < (*tree)->right->n)
{
(*tree)->right = binary_tree_rotate_right((*tree)->right);
return (binary_tree_rotate_left(*tree));
}

return (*tree);
}
