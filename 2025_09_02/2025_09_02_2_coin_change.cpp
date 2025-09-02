// Author: Juyoung Moon
// https://leetcode.com/problems/coin-change/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, Sep 02, 2025)

// HW are the following 2 problems:
// 1. Implement Trie (Prefix Tree)
// 2. Coin Change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int kMax = 100000000;
        vector<int> dp(amount + 1, kMax);
        
        dp[0] = 0;
        for (int c : coins) {
            if (c < dp.size()) {
                dp[c] = 1;
            }
        }
        
        for (int currAmt = 1; currAmt < dp.size(); currAmt++) {
            for (int coinAmt : coins) {
                int prevIdx = currAmt - coinAmt;

                if (prevIdx >= 0) {
                    dp[currAmt] = min(dp[currAmt], dp[prevIdx] + 1);
                }
            }
        }

        return (dp[amount] == kMax) ? -1 : dp[amount];
    }
};
