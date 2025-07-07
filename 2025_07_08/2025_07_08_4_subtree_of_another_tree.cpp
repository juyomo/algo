// Author: Juyoung Moon
// https://leetcode.com/problems/subtree-of-another-tree/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 8, 2025)

// HW are the following 4 problems:
// 1. Palindrome Number
// 2. Convert Sorted Array to Binary Search Tree
// 3. Reverse Bits
// 4. Subtree of Another Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool sameTree(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) {
            return true;
        } else if (a == nullptr || b == nullptr) {
            return false;
        } else if (a->val != b->val) {
            return false;
        }

        return sameTree(a->left, b->left) && sameTree(a->right, b->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        } else if (root == nullptr || subRoot == nullptr) {
            return false;
        }

        return sameTree(root, subRoot)
                || isSubtree(root->left, subRoot)
                || isSubtree(root->right, subRoot);
    }
};
