// Author: Juyoung Moon
// https://leetcode.com/problems/symmetric-tree/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 1, 2025)

// HW are the following 5 problems:
// 1. #136 Single Number
// 2. #234 Palindrome Linked List
// 3. #283 Move Zeroes
// 4. #101 Symmetric Tree
// 5. #268 Missing Number

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
    bool isMirror(TreeNode* r1, TreeNode* r2) {
        if (r1 == nullptr && r2 == nullptr) {
            return true;
        } else if (r1 == nullptr || r2 == nullptr) {
            return false;
        } else if (r1->val != r2->val) {
            return false;
        }

        return isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
};
