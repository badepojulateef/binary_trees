#include "binary_trees.h"
bst_t *bst_node(bst_t *parent, int value);

/**
 * bst_insert - Insert
 *
 * @tree: Pointer
 * @value: Integer
 *
 * Return: bst
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
		return (*tree = bst_node(NULL, value));

	if (value == (*tree)->n)
		return (NULL);

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
			return ((*tree)->left = bst_node(*tree, value));
		else
			return (bst_insert(&((*tree)->left), value));
	}
	else
	{
		if ((*tree)->right == NULL)
			return ((*tree)->right = bst_node(*tree, value));
		else
			return (bst_insert(&((*tree)->right), value));
	}
}

/**
 * bst_node - Insert
 *
 * @parent: Pointer
 * @value: Integer
 *
 * Return: bst
 */
bst_t *bst_node(bst_t *parent, int value)
{
	bst_t *new_node = malloc(sizeof(bst_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	return (new_node);
}
