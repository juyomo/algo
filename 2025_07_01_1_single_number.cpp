// Author: Juyoung Moon
// https://leetcode.com/problems/single-number/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 1, 2025)

// HW are the following 5 problems:
// 1. #136 Single Number
// 2. #234 Palindrome Linked List
// 3. #283 Move Zeroes
// 4. #101 Symmetric Tree
// 5. #268 Missing Number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xord = 0;
        for (int n : nums) {
            xord = xord ^ n;
        }
        return xord;
    }
};
