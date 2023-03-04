#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 *
 * @tree: Pointer
 *
 * @value: Integer
 *
 * Return: Pointer to the node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
	} else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
	} else
		return (NULL);

	int balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
	{
		return (binary_tree_rotate_right(*tree));
	}

	if (balance < -1 && value > (*tree)->right->n)
	{
		return (binary_tree_rotate_left(*tree));
	}

	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}
	return (*tree);
}
