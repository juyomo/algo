// Author: Juyoung Moon
// https://leetcode.com/problems/product-of-array-except-self/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, Sep 09, 2025)

// HW are the following 2 problems:
// 1. Product of Array Except Self
// 2. Min Stack

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixes(nums.size());
        vector<int> suffixes(nums.size());
        int lastIndex = nums.size() - 1;

        prefixes[0] = 1;
        suffixes[lastIndex] = 1;
        for (int i = 1; i < nums.size(); i++) {
            prefixes[i] = prefixes[i-1] * nums[i-1];
            suffixes[lastIndex-i] = suffixes[lastIndex-i+1] * nums[lastIndex-i+1];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = prefixes[i] * suffixes[i];
        }
        return nums;
    }
};
