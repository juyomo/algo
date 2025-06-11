// Author: Juyoung Moon
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int findMax(int a, int b) {
        return a > b ? a : b;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return 1 + findMax(maxDepth(root->left), maxDepth(root->right)); 
        }
    }
};
