// Author: Juyoung Moon
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
private:
    TreeNode* recur(const vector<int>& nums, int min, int max) {
        if (min > max) {
            return nullptr;
        }

        int mid = (min + max) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        if (min != max) {
            root->left = recur(nums, min, mid-1);
            root->right = recur(nums, mid+1, max);
        }

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int min = 0;
        int max = nums.size() - 1;

        return recur(nums, min, max);
    }
};