// Author: Juyoung Moon
// https://leetcode.com/problems/number-of-1-bits/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 24, 2025)

// HW are the following 5 problems:
// 1. #844 Backspace String Compare
// 2. #338 Counting Bits
// 3. #100 Same Tree
// 4. #191 Number of 1 Bits
// 5. #14 Longest Common Prefix

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                count++;
            }
            n = n / 2;
        }
        return count;
    }
};
