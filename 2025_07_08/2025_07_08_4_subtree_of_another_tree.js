// Author: Juyoung Moon
// https://leetcode.com/problems/subtree-of-another-tree/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 8, 2025)

// HW are the following 4 problems:
// 1. Palindrome Number
// 2. Convert Sorted Array to Binary Search Tree
// 3. Reverse Bits
// 4. Subtree of Another Tree

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} subRoot
 * @return {boolean}
 */

function sameTree(a, b) {
    if (a == null && b == null) {
        return true;
    } else if (a == null || b == null) {
        return false;
    } else if (a.val != b.val) {
        return false;
    }

    return sameTree(a.left, b.left) && sameTree(a.right, b.right);
}

var isSubtree = function(root, subRoot) {
    if (root == null && subRoot == null) {
        return true;
    } else if (root == null || subRoot == null) {
        return false;
    } 
    return sameTree(root, subRoot) || isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
};
