// Author: Juyoung Moon
// https://leetcode.com/problems/roman-to-integer/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 17, 2025)

// HW are the following 5 problems:
// 1. Diameter of Binary Tree
// 2. Middle of the Linked List
// 3. Maximum Depth of Binary Tree
// 4. Contains Duplicate
// 5. Roman to Integer

class Solution {
public:
    unordered_map<char, int> m = {
        {'I' , 1},
        {'V' , 5},
        {'X' , 10},
        {'L' , 50},
        {'C' , 100},
        {'D' , 500},
        {'M' , 1000},
    };
    unordered_map<char, unordered_set<char>> neg = {
        {'I' , {'V', 'X'}},
        {'X' , {'L', 'C'}},
        {'C' , {'D', 'M'}},
    };
    
    int romanToInt(string s) {
        int sum = 0;
        int idx = 0;
        int len = s.size();
        while (idx < len) {
            int score = m[s[idx]];
            char next = idx < len - 1 ? s[idx + 1] : '_';
            int sign = 1;
            if (neg[s[idx]].count(next) > 0) {
                sign = -1;
            }
            sum += sign * score;
            idx++;
        }    

        return sum;  
    }
};
