// Author: Juyoung Moon
// https://leetcode.com/problems/insert-interval/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 22, 2025)

// HW are the following 2 problems:
// 1. Maximum Subarray
// 2. Insert Interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int st = newInterval[0];
        int ed = newInterval[1];

        vector<vector<int>> res;
        int idx = 0;
        while (idx < intervals.size() && intervals[idx][1] < st) {
            res.push_back(intervals[idx]);
            idx++;
        }

        if (idx >= intervals.size()) {
            res.push_back(newInterval);
            return res;
        }

        st = min(st, intervals[idx][0]);
        while (idx < intervals.size() && intervals[idx][0] <= ed) {
            idx++;
        }

        if (idx >= 1 && intervals[idx-1][1] > ed) {
            ed = intervals[idx-1][1];
        }
        res.push_back({st, ed});

        while (idx < intervals.size()) {
            res.push_back(intervals[idx]);
            idx++;
        }
        return res;
    }
};
