// Author: Juyoung Moon
// https://leetcode.com/problems/min-stack/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, Sep 09, 2025)

// HW are the following 2 problems:
// 1. Product of Array Except Self
// 2. Min Stack

class MinStack {
private:
    stack<pair<int, int>> stk_;

public:
    MinStack() {
    }
    
    void push(int val) {
        int currMin = val;
        if (stk_.size() > 0 && stk_.top().second < currMin) {
            currMin = stk_.top().second;
        }
        stk_.push(make_pair(val, currMin));
        
    }
    
    void pop() {
        stk_.pop();
    }
    
    int top() {
        return stk_.empty() ? 0 : stk_.top().first;
    }
    
    int getMin() {
        return stk_.empty() ? 0 : stk_.top().second;
    }
};
