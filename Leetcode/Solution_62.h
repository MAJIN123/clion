//
// Created by Maloney on 17-6-11.

//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_62_H
#define LEETCODE_SOLUTION_62_H

#endif //LEETCODE_SOLUTION_62_H

class Solution_62 {
    //this solution runs in O(n^2) time and costs O(m*n) space
public:
    /**
     * Unique Paths
     * @param m represents row
     * @param n represts col
     * @return the amount of ways to get out of the array
     */
    int uniquePaths(int m, int n) {
        int table[m][n] = {1};
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                table[i][j] = table[i - 1][j] + table[i][j - 1];
        return table[m - 1][n - 1];

    }
};
class Solution_62_b {
    //this solution runs in O(n^2) time and costs O(2m) space
public:
    /**
     * Unique Paths
     * @param m represents row
     * @param n represents col
     * @return the amount of ways to get out of the array
     */
    int uniquePaths(int m, int n) {
        if (m > n)
            return uniquePaths(n, m);
        int cur[m] = {1};
        int pre[m] = {1};
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j)
                cur[j] = pre[j] + cur[j - 1];
            swap(cur, pre);
        }
        return cur[m - 1];
    }
};
class Solution_62_c {
    //this solution runs in O(n^2) time and costs O(min(m,n)) space
public:
    /**
     * Unique Paths
     * @param m represents row
     * @param n represents col
     * @return the amount of ways to get out of the array
     */
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        int cur[m] = {1};
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1];
        return cur[m - 1];
    }
};
class Solution_63_myself {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int table[m][n] = {1};

        int i;
        for (i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1)
                break;
        }
        for (int j = i; j < n; ++j)
            table[0][j] = 0;

        int p;
        for (p = 0; p < m; ++p)
            if (obstacleGrid[p][0] == 1)
                break;
        for (int j = p; j < m; ++j)
            table[j][0] = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    table[i][j] = 0;
                else
                    table[i][j] = table[i - 1][j] + table[i][j - 1];
            }
        }
        return table[m - 1][n - 1];
    }
};
class Solution_63_other {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};
class Solution_63_other_b {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> pre(m, 0);
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                pre[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (!obstacleGrid[0][j]) {
                cur[0] = pre[0];
                if (cur[0]) flag = true;
            }
            else cur[0] = 0;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] = cur[i - 1] + pre[i];
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0;
            }
            if (!flag) return 0;
            swap(pre, cur);
        }
        return pre[m - 1];
    }
};
class Solution_63_other_c {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                cur[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (obstacleGrid[0][j])
                cur[0] = 0;
            else flag = true;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] += cur[i - 1];
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0;
            }
            if (!flag) return 0;
        }
        return cur[m - 1];
    }
};