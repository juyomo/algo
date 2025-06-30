// Author: Juyoung Moon
// https://leetcode.com/problems/missing-number/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 1, 2025)

// HW are the following 5 problems:
// 1. #136 Single Number
// 2. #234 Palindrome Linked List
// 3. #283 Move Zeroes
// 4. #101 Symmetric Tree
// 5. #268 Missing Number

/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let n = nums.length;
    let expected = n * (n + 1) / 2;
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum += nums[i];
    }
    return expected - sum;
};
