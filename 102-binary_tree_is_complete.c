#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue = NULL;
	size_t front = 0, back = 0, size = 0;
	int complete = 1, has_missing = 0;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[back++] = (binary_tree_t *)tree;
	size++;

	while (front < size)
	{
		binary_tree_t *node = queue[front++];

		if (node->left != NULL)
		{
			if (has_missing)
			{
				complete = 0;
				break;
			}
			queue[back++] = node->left;
			size++;
		}
		else
		{
			has_missing = 1;
		}

		if (node->right != NULL)
		{
			if (has_missing)
			{
				complete = 0;
				break;
			}
			queue[back++] = node->right;
			size++;
		}
		else
		{
			has_missing = 1;
		}
	}

	free(queue);

	return (complete);
}
