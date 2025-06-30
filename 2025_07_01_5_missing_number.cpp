// Author: Juyoung Moon
// https://leetcode.com/problems/missing-number/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 1, 2025)

// HW are the following 5 problems:
// 1. #136 Single Number
// 2. #234 Palindrome Linked List
// 3. #283 Move Zeroes
// 4. #101 Symmetric Tree
// 5. #268 Missing Number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); // expect 0 to n
        /*
        // SOLN #1.
        vector<int> found(n + 1, false);
        for (int k : nums) {
            found[k] = true;
        }
        for (int i = 0; i < found.size(); i++) {
            if (!found[i]) {
                return i;
            }
        }
        return -1;
        */

        // SOLN #2.
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int k : nums) {
            actualSum += k;
        }
        return expectedSum - actualSum;
    }
};
