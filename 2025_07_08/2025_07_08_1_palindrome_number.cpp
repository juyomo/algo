// Author: Juyoung Moon
// https://leetcode.com/problems/palindrome-number/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 8, 2025)

// HW are the following 4 problems:
// 1. Palindrome Number
// 2. Convert Sorted Array to Binary Search Tree
// 3. Reverse Bits
// 4. Subtree of Another Tree

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        }
        vector<int> v;
        while (x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        int len = v.size();
        for (int i = 0; i < len; i++) {
            if (v[i] != v[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
