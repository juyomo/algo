// Author: Juyoung Moon
// https://leetcode.com/problems/backspace-string-compare/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 24, 2025)

// HW are the following 5 problems:
// 1. #844 Backspace String Compare
// 2. #338 Counting Bits
// 3. #100 Same Tree
// 4. #191 Number of 1 Bits
// 5. #14 Longest Common Prefix

class Solution {
public:
    void createStackFromStr(const string& str, stack<char>& stk) {
        for (char c : str) {
            if (c == '#') {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(c);
                cout << c << " ";
            }
        }
        cout << endl;
    }
    bool backspaceCompare(string s, string t) {
        stack<char> s_stk;
        stack<char> t_stk;

        createStackFromStr(s, s_stk);
        createStackFromStr(t, t_stk);
       
        if (s_stk.size() != t_stk.size()) {
            return false;
        }

        while (!s_stk.empty()) {
            if (s_stk.top() != t_stk.top()) {
                return false;
            }
            s_stk.pop();
            t_stk.pop();
        }
        return true;
    }
};
