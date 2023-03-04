#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 *
 * Return: pointer to the ancestor node
 *         NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *node1 = first, *node2 = second;

	/* Trvaerse up from both nodes until they are at the same level */
	while (node1 != node2)
	{
		if (node1 == NULL)
			node1 = second;
		else
			node1 = node1->parent;

		if (node2 == NULL)
			node2 = first;
		else
			node2 = node2->parent;
	}
	return ((binary_tree_t *)node1);
}
