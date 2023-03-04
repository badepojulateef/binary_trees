#include "binary_trees.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int is_bst_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
        if (tree == NULL)
                return (0);

        return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - helper function to check if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value that a node can take
 * @max: maximum value that a node can take
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
        if (tree == NULL)
                return (1);

        if (tree->n < min || tree->n > max)
                return (0);

        return (is_bst_helper(tree->left, min, tree->n - 1) &&
                        is_bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If @tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (MAX(left_height, right_height) + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor of the tree. If @tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_is_avl_helper - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if @tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (1);

	balance = binary_tree_balance(tree);

	if (abs(balance) > 1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left) &&
			binary_tree_is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if @tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int is_bst, is_avl;

	if (tree == NULL)
		return (0);

	is_bst = binary_tree_is_bst(tree);
	is_avl = binary_tree_is_avl_helper(tree);

	return (is_bst && is_avl);
}

