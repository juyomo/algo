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
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nodes;
        while (head != nullptr) {
            nodes.push_back(head->val);
            head = head->next;
        }

        int i = 0;
        int j = nodes.size() - 1;

        while (i < j) {
            if (nodes[i] != nodes[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
