// Author: Juyoung Moon
// https://leetcode.com/problems/same-tree/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 24, 2025)

// HW are the following 5 problems:
// 1. #844 Backspace String Compare
// 2. #338 Counting Bits
// 3. #100 Same Tree
// 4. #191 Number of 1 Bits
// 5. #14 Longest Common Prefix

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        } else {
            return (p->val == q->val) &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);
        }
    }
};
