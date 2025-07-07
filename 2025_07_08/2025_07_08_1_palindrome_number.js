// Author: Juyoung Moon
// https://leetcode.com/problems/palindrome-number/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 8, 2025)

// HW are the following 4 problems:
// 1. Palindrome Number
// 2. Convert Sorted Array to Binary Search Tree
// 3. Reverse Bits
// 4. Subtree of Another Tree

/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let str = x.toString();
    let len = str.length;
    for (let i = 0; i < len/2; i++) {
        if (str[i] !== str[len-1-i])
            return false;
    }
    return true;
};
