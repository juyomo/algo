// Author: Juyoung Moon
// https://leetcode.com/problems/01-matrix/
// Solved for LeetCode 알고리즘 스터디 (Due Tue, July 29, 2025)

// HW are the following 2 problems:
// 1. 01 Matrix
// 2. K Closest Points to Origin

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int dr[] = {0, 1, -1, 0};
        const int dc[] = {1, 0, 0, -1};

        int height = mat.size();
        int width = mat[0].size();

        queue<pair<int, int>> tovisit;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (mat[i][j] == 0) {
                    tovisit.push(make_pair(i, j));
                } else {
                    mat[i][j] = 1000000;
                }
            }
        }

        while (!tovisit.empty()) {
            int r = tovisit.front().first;
            int c = tovisit.front().second;
            int currDist = mat[r][c];
            tovisit.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < height && nc < width && mat[nr][nc] > currDist + 1) {
                    mat[nr][nc] = currDist + 1;
                    tovisit.push(make_pair(nr, nc));
                }
            }
        }

        return mat;
    }
};
