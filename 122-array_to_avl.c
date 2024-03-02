#include "binary_trees.h"

/**
 * array_to_avl_ Tree recursively
 * @tree: A pointer to the root node of the AVL tree
 * @array: Pointer to the first element of the array
 * @start: The starting index of the current sub-array
 * @end: The ending index of the current sub-array
 *
 * Return: A pointer to the root node of the AVL tree
 */
avl_t *array_to_avl_recursive(avl_t *tree, int *array, size_t start,
size_t end)
{
if (start > end)
return (NULL);

size_t mid = (start + end) / 2;

tree = avl_insert(&tree, array[mid]);
if (tree == NULL)
return (NULL);

array_to_avl_recursive(tree, array, start, mid - 1);
array_to_avl_recursive(tree, array, mid + 1, end);

return (tree);
}

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 *
 * Return: A pointer to tor NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
if (array == NULL || size == 0)
return (NULL);

avl_t *root = NULL;

root = array_to_avl_recursive(root, array, 0, size - 1);

return (root);
}

