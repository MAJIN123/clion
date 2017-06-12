//
// Created by Maloney on 17-6-12.

//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_64_H
#define LEETCODE_SOLUTION_64_H

#endif //LEETCODE_SOLUTION_64_H
class Solution_64 {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> table(grid);
        for (int i = 1; i < n; ++i)
            table[0][i] += table[0][i - 1];
        for (int i = 1; i < m; ++i)
            table[i][0] += table[i - 1][0];
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                table[i][j] += min(table[i][j - 1], table[i - 1][j]);
            }
        return table[m - 1][n - 1];
    }
};
class Solution_64_b {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) {
            cur[0] = pre[0] + grid[0][j];
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            swap(pre, cur);
        }
        return pre[m - 1];
    }
};
class Solution_64_c {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j];
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};