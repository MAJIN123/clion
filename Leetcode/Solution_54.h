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
/**
 * Spiral Matrix II
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * For example,
 * Given n = 3,
 * You should return the following matrix:
    [
     [ 1, 2, 3 ],
     [ 8, 9, 4 ],
     [ 7, 6, 5 ]
    ]
 */
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
class Solution_59 {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dig = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int u = 0, d = n - 1, l = 0, r = n - 1;
        while (dig <= n * n) {
            for (int col = l; col <= r; ++col) {
                res[u][col] = dig;
                ++dig;
            }
            ++u;
            for (int row = u; row <= d; ++row) {
                res[row][r] = dig;
                ++dig;
            }
            --r;
            for (int col = r; col >= l; --col) {
                res[d][col] = dig;
                ++dig;
            }
            --d;
            for (int row = d; row >= u; --row) {
                res[row][l] = dig;
                ++dig;
            }
            ++l;
        }
        return res;
    }
};
class Solution_59_b {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n));
        int k = 1, i = 0;
        while (k <= n * n) {
            int j = i;
            // four steps
            while (j < n - i)             // 1. horizonal, left to right
                ret[i][j++] = k++;
            j = i + 1;
            while (j < n - i)             // 2. vertical, top to bottom
                ret[j++][n - i - 1] = k++;
            j = n - i - 2;
            while (j > i)                  // 3. horizonal, right to left
                ret[n - i - 1][j--] = k++;
            j = n - i - 1;
            while (j > i)                  // 4. vertical, bottom to  top
                ret[j--][i] = k++;
            i++;      // next loop
        }
        return ret;
    }
};