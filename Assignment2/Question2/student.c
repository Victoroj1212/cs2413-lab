/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int absVal(int x) {
    return (x < 0) ? -x : x;
}

static int checkAVL(struct TreeNode* root, long min, long max) {
    if (root == NULL) {
        return 0;
    }

    // strict BST property
    if (root->val <= min || root->val >= max) {
        return -1;
    }

    int leftHeight = checkAVL(root->left, min, root->val);
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkAVL(root->right, root->val, max);
    if (rightHeight == -1) {
        return -1;
    }

    // AVL balance property
    if (absVal(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isAVL(struct TreeNode* root) {
    return checkAVL(root, -2147483649L, 2147483648L) != -1;
}