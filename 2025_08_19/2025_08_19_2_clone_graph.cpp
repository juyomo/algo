// Author: Juyoung Moon
// https://leetcode.com/problems/clone-graph/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, Aug 19, 2025)

// HW are the following 2 problems:
// 1. Binary Tree Level Order Traversal
// 2. Clone Graph

class Solution {
public:
    Node* cloneGraphHelper(Node* node, unordered_map<Node*, Node*>& visited) {
        if (node == nullptr) {
            return nullptr;
        }
        
        Node* head = new Node(node->val);
        visited[node] = head;
        
        const vector<Node*>& oldNs = node->neighbors;
        vector<Node*>& newNs = head->neighbors;
        
        for (int i = 0; i < oldNs.size(); i++) {
            if (visited.find(oldNs[i]) == visited.end()) {
                newNs.push_back(cloneGraphHelper(oldNs[i], visited));
            } else {
                newNs.push_back(visited[oldNs[i]]);
            }
        }
        return head;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> visited;
        return cloneGraphHelper(node, visited);
    }
};

