// Author: Juyoung Moon
// https://leetcode.com/problems/implement-trie-prefix-tree/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, Sep 02, 2025)

// HW are the following 2 problems:
// 1. Implement Trie (Prefix Tree)
// 2. Coin Change

class Node {
public:
    char val;
    vector<Node*> children;
    bool last;

    Node() {
        val = '_';
        children.resize(26);
        last = false;
    }

    Node(char c) {
        val = c;
        children.resize(26);
        last = false;
    }
};

class Trie {
private:
    int charToIdx(char c) {
        return c - 'a';
    }

public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            int idx = charToIdx(c);
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Node(c);
            }
            curr = curr->children[idx];
            if (i == word.size() - 1) {
                curr->last = true;
            }
        }
    }
    
    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            int idx = charToIdx(c);

            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
            if (i == word.size() - 1) {
                return curr->last;
            }
        }
        return curr == nullptr;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int idx = charToIdx(c);

            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};
