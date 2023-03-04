#include "binary_trees.h"

/**
 * avl_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree
 * (left subtree height - right subtree height),
 * or 0 if the tree is NULL
 */
int avl_balance(const avl_t *tree)
{
	int height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? tree->left->height + 1 : 0;
	height_r = tree->right ? tree->right->height + 1 : 0;

	return (height_l - height_r);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1));
}

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @start: Index of the first element in the array to use
 * @end: Index of the last element in the array to use
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *build_avl_tree(int *array, int start, int end)
{
	int mid = (start + end) / 2;
	avl_t *node;

	if (start > end)
		return (NULL);

	node = binary_tree_node(NULL, array[mid]);
	if (node == NULL)
		return (NULL);

	node->left = build_avl_tree(array, start, mid - 1);
	node->right = build_avl_tree(array, mid + 1, end);

	node = avl_balance(node);

	return (node);
}
