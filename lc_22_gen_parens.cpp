// Author: Juyoung Moon
// Solved on: Monday, June 30, 2025 (KST).
// Part of Christian Coffee Chat IT Group Algorithm Study.

class Solution {
public:
    void backtrack(vector<string>& res, int open, int close, string s) {
        if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }

        if (open > 0) {
            backtrack(res, open - 1, close, s + "(");
        }

        if (open < close && close > 0) {
            backtrack(res, open, close - 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        backtrack(res, n, n, s);
        return res;
    }
};
