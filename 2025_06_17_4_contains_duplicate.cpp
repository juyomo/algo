// Author: Juyoung Moon
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 17, 2025)

// HW are the following 5 problems:
// 1. Diameter of Binary Tree
// 2. Middle of the Linked List
// 3. Maximum Depth of Binary Tree
// 4. Contains Duplicate
// 5. Roman to Integer

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*      
        // SOLN 1. Sort. O(n log n)
        std::sort(nums.begin(), nums.end()); 

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i]) {
                return true;
            }
        }
        return false;
        */

        // SOLN 2. Hash. O(n)
        std::unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            } else {
                seen.insert(num);
            }
        }
        return false;
    }
};
