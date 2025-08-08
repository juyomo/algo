// Author: Juyoung Moon
// https://leetcode.com/problems/3sum/description/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, Aug 12, 2025)

// HW are the following 2 problems:
// 1. Longest Substring without Repeating Characters
// 2. 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        unordered_map<int, int> counts;
        for (int i = 0; i < num.size(); i++) {
            if (counts[num[i]] < 3) {
                counts[num[i]]++;
            }
        }

        vector<int> nums;
        for (const auto& p : counts) {
            for (int j = 0; j < p.second; j++) {
                nums.push_back(p.first);
            }
        }

        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int lookFor = -1 * (nums[i] + nums[j]);
                if (indices.find(lookFor) != indices.end() && indices[lookFor] != i && indices[lookFor] != j) {
                    res.push_back({lookFor, nums[i], nums[j]});
                }
            }
        }

        for (int i = 0; i < res.size(); i++) {
            sort(res[i].begin(), res[i].end());
        }
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            return res;
        }

        vector<vector<int>> ans;
        ans.push_back(res[0]);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] != res[i-1]) {
                ans.push_back(res[i]);
            }
        }
        return ans;
    }
};
