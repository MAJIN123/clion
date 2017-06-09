//
// Created by Maloney on 17-6-9.

//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_54_H
#define LEETCODE_SOLUTION_54_H

#endif //LEETCODE_SOLUTION_54_H

/**
 * Spiral Matrix
 * Given a matrix of m x n elements (m rows, n columns),
 * return all elements of the matrix in spiral order.
 */
class Solution_54 {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int row = matrix.size();
        int col;
        if (row)
            col = matrix[0].size();
        else
            return res;
        int x = 0, y = col - 1, a = 0, b = row - 1;
        hh(matrix, a, b, x, y, res);
        return res;
    }

private:
    void hh(vector<vector<int>> &matrix, int a, int b, int x, int y, vector<int> &res) {
        if (x > y && a > b) {
            return;
        }
        for (int i = x; i <= y; ++i)
            res.push_back(matrix[a][i]);
        for (int i = a + 1; i < b; ++i)
            res.push_back(matrix[i][y]);
        for (int i = y; i >= x && b != a; --i)
            res.push_back(matrix[b][i]);
        for (int i = b - 1; i > a && x != y; --i)
            res.push_back(matrix[i][x]);
        ++a;
        --b;
        ++x;
        --y;
        hh(matrix, a, b, x, y, res);
    }
};
class Solution_54_b {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral(m * n);
        int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
        while (true) {
            // up
            for (int col = l; col <= r; col++) spiral[k++] = matrix[u][col];
            if (++u > d) break;
            // right
            for (int row = u; row <= d; row++) spiral[k++] = matrix[row][r];
            if (--r < l) break;
            // down
            for (int col = r; col >= l; col--) spiral[k++] = matrix[d][col];
            if (--d < u) break;
            // left
            for (int row = d; row >= u; row--) spiral[k++] = matrix[row][l];
            if (++l > r) break;
        }
        return spiral;
    }
};