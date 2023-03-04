#include "binary_trees.h"
bst_t *bst_minimum(bst_t *root);

/**
 * bst_remove - Entry point
 *
 * @root: Pointer
 * @value: Int
 *
 * Return: 0 on success, error code on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp;

			temp = root->right;
			free(root);
			return (temp);
		} else if (root->right == NULL)
		{
			bst_t *temp;

			temp = root->left;
			free(root);
			return (temp);
		}
		bst_t *temp;

		temp = bst_minimum(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * bst_minimum - Entry point
 * @root: Int
 * Return: 0 on success, error code on failure
 */
bst_t *bst_minimum(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
