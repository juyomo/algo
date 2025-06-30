// Author: Juyoung Moon
// https://leetcode.com/problems/move-zeroes/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 1, 2025)

// HW are the following 5 problems:
// 1. #136 Single Number
// 2. #234 Palindrome Linked List
// 3. #283 Move Zeroes
// 4. #101 Symmetric Tree
// 5. #268 Missing Number

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let placeToFill = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] != 0) {
            nums[placeToFill] = nums[i];
            placeToFill++;
        }
    }
    for (let i = placeToFill; i < nums.length; i++) {
        nums[i] = 0;
    }
    return nums;
};
