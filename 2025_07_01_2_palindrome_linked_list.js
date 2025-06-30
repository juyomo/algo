// Author: Juyoung Moon
// https://leetcode.com/problems/palindrome-linked-list/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 1, 2025)

// HW are the following 5 problems:
// 1. #136 Single Number
// 2. #234 Palindrome Linked List
// 3. #283 Move Zeroes
// 4. #101 Symmetric Tree
// 5. #268 Missing Number

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let elems = [];
    while (head != null) {
        elems.push(head.val);
        head = head.next;
    }
    let len = elems.length;
    for (let i = 0; i * 2 <= len; i++) {
        if (elems[i] != elems[len - 1 - i]) {
            return false;
        }
    }
    return true;
};
