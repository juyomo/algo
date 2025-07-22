// Author: Juyoung Moon
// https://leetcode.com/problems/maximum-subarray/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 22, 2025)

// HW are the following 2 problems:
// 1. Maximum Subarray
// 2. Insert Interval

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) { 
            return 0;
        }
        
        vector<int> dp(len);
        dp[0] = nums[0];
        int currMax = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if (dp[i] > currMax) {
                currMax = dp[i];
            }
        }

        return currMax;
    }
};
