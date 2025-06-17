// Author: Juyoung Moon
// https://leetcode.com/problems/diameter-of-binary-tree/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 17, 2025)

// HW are the following 5 problems:
// 1. Diameter of Binary Tree
// 2. Middle of the Linked List
// 3. Maximum Depth of Binary Tree
// 4. Contains Duplicate
// 5. Roman to Integer

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
    // diameter
    // - passes through root: leftDepth + rightDepth
    // - doesn't pass through root: max(leftMaxDia, rightMaxDia)
    // need to pass up depth and maxDia
    // - depth = max(leftDepth, rightDepth) + 1;
    // - maxDia = max(leftDepth + rightDepth, max(leftMaxDia, rightMaxDia))
    void diaRecur(TreeNode* root, int& depth, int& diameter) {
        if (root == nullptr) {
            depth = 0;
            diameter = 0;
            return;
        }

        int leftDepth;
        int rightDepth;
        int leftMaxDia;
        int rightMaxDia;
        diaRecur(root->left, leftDepth, leftMaxDia);
        diaRecur(root->right, rightDepth, rightMaxDia);
        depth = max(leftDepth, rightDepth) + 1;
        diameter = max(leftDepth + rightDepth, max(leftMaxDia, rightMaxDia));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int depth, diameter;
        diaRecur(root, depth, diameter);

        return diameter;
    }
};