// Author: Juyoung Moon
// Solved on: Sat, June 28, 2025 (KST).
// https://www.codetree.ai/ko/frequent-problems/samsung-sw/problems/firewall-installation/description
// 58ms, 0MB

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Coord;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int calcSafe(vector<vector<int>> map, const vector<int>& wallsToAdd, queue<Coord> tovisit) {
    int height = map.size();
    int width = map[0].size();

    for (int n : wallsToAdd) {
        int r = n / width;
        int c = n % width;
        map[r][c] = 1;
    }

    while (!tovisit.empty()) {
        int r = tovisit.front().first;
        int c = tovisit.front().second;
        tovisit.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < height && nc < width && map[nr][nc] == 0) {
                map[nr][nc] = 2;
                tovisit.push(make_pair(nr, nc));
            }
        }
    }

    int safeArea = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 0) {
                safeArea++;
            }
        }
    }
    return safeArea;
}

void backtrack(const vector<vector<int>>& map,
               const vector<int>& empties, 
               vector<int>& chosen,
               int& maxSoFar,
               int idx,
               const queue<Coord>& tovisit) {
    if (chosen.size() == 3) {
        int currMax = calcSafe(map, chosen, tovisit);
        if (currMax > maxSoFar) {
            maxSoFar = currMax;
        }
        return;
    }

    if (idx >= empties.size()) {
        return;
    }

    chosen.push_back(empties[idx]);
    backtrack(map, empties, chosen, maxSoFar, idx + 1, tovisit);

    chosen.pop_back();
    backtrack(map, empties, chosen, maxSoFar, idx + 1, tovisit);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<int> empties;
    queue<Coord> tovisit;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                empties.push_back(i * m + j);
            } else if (map[i][j] == 2) {
                tovisit.push(make_pair(i, j));
            }
        }
    }

    // choose 3 from empties - to put the walls in
    int maxSoFar = 0;
    vector<int> chosen;
    backtrack(map, empties, chosen, maxSoFar, 0, tovisit);
    cout << maxSoFar << endl;
    return 0;
}
