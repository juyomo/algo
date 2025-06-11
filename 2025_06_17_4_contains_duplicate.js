// Author: Juyoung Moon
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 17, 2025)

// HW are the following 5 problems:
// 1. Diameter of Binary Tree
// 2. Middle of the Linked List
// 3. Maximum Depth of Binary Tree
// 4. Contains Duplicate
// 5. Roman to Integer

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let seen = new Set();
    for (let i = 0; i < nums.length; i++) {
        let curr = nums[i];
        if (seen.has(curr)) {
            return true;
        } else {
            seen.add(nums[i]);
        }
    }
    return false;
};
