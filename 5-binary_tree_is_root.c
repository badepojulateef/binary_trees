#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks is a node is a root
 *
 * @node: Pointer to the node to be checked
 *
 * Return: int if true, otherwise 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);

	return (0);
}
