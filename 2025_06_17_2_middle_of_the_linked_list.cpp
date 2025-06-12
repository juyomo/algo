// Author: Juyoung Moon
// https://leetcode.com/problems/middle-of-the-linked-list/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, June 17, 2025)

// HW are the following 5 problems:
// 1. Diameter of Binary Tree
// 2. Middle of the Linked List
// 3. Maximum Depth of Binary Tree
// 4. Contains Duplicate
// 5. Roman to Integer

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
    ListNode* middleNode(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) {
                return slow;
            }
            fast = fast->next;
        }
        delete dummy;
        return slow;
    }
};
