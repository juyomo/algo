// Author: Juyoung Moon
// https://leetcode.com/problems/validate-binary-search-tree/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, Sep 16, 2025)

// HW are the following 2 problems:
// 1. Validate Binary Search tree (#98)
// 2. Number of Islands (#200)

class Solution {
private:
    bool isValid(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }

        if (root->val >= max || root->val <= min) {
            return false;
        }

        bool res = (root->left == nullptr || root->val > root->left->val) && 
               (root->right == nullptr || root->val < root->right->val) && 
               isValid(root->left, min, root->val) &&
               isValid(root->right, root->val, max);

        return res;
    }

public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
