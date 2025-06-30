// Author: Juyoung Moon
// https://leetcode.com/problems/move-zeroes/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 1, 2025)

// HW are the following 5 problems:
// 1. #136 Single Number
// 2. #234 Palindrome Linked List
// 3. #283 Move Zeroes
// 4. #101 Symmetric Tree
// 5. #268 Missing Number

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int indexToPutElem = 0;
        int numZeros = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ++numZeros;
            } else {
                nums[indexToPutElem] = nums[i];
                ++indexToPutElem;
            }
        }

        for (int i = nums.size() - numZeros; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
