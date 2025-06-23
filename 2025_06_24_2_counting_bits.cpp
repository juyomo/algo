// Author: Juyoung Moon
// https://leetcode.com/problems/counting-bits/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 24, 2025)

// HW are the following 5 problems:
// 1. #844 Backspace String Compare
// 2. #338 Counting Bits
// 3. #100 Same Tree
// 4. #191 Number of 1 Bits
// 5. #14 Longest Common Prefix

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        res[0] = 0;
        int intervalSize = 1;
        while (intervalSize < res.size()) {
            for (int i = intervalSize; i < intervalSize * 2 && i < res.size(); i++) {
                res[i] = res[i - intervalSize] + 1;
            }
            intervalSize *= 2;
        }
        return res;
    }
};
