#include "binary_trees.h"

void traverse_level(const binary_tree_t *tree, void (*func)(int), int level);
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = binary_tree_height(tree);
	int i;

	if (tree == NULL || func == NULL)
		return;

	for (i = 0; i <= height; i++)
		traverse_level(tree, func, i);
}

/**
 * traverse_level - traverses the given level of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: level to traverse
 *
 * Return: void
 */
void traverse_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		traverse_level(tree->left, func, level - 1);
		traverse_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: the height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);

	return (1 + (height_l > height_r ? height_l : height_r));
}
