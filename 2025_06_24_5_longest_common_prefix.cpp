// Author: Juyoung Moon
// https://leetcode.com/problems/longest-common-prefix/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 24, 2025)

// HW are the following 5 problems:
// 1. #844 Backspace String Compare
// 2. #338 Counting Bits
// 3. #100 Same Tree
// 4. #191 Number of 1 Bits
// 5. #14 Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        bool isSame = true;
        for (int i = 0; i < strs[0].length() && isSame; i++) {
            char curr = strs[0][i];
            for (const auto& str : strs) {
                if (str[i] != curr) {
                    isSame = false;
                }
            }
            if (isSame) {
                res += curr;
            }
        }
        return res;
    }
};
