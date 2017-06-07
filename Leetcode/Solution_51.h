//
// Created by Maloney on 17-6-7.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_51_H
#define LEETCODE_SOLUTION_51_H

#endif //LEETCODE_SOLUTION_51_H
/**
 * N-Queens
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
 * both indicate a queen and an empty space respectively.
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
 */
class Solution_A {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        solveNQueens(res, tmp, 0, n);
        return res;
    }

private:
    void solveNQueens(vector<vector<string>> &res, vector<string> &tmp, int row, int &n) {
        if (row == n) {
            res.push_back(tmp);
            return;
        }
        for (int col = 0; col != n; ++col) {
            if (isvalid(tmp, row, col, n)) {
                tmp[row][col] = 'Q';
                solveNQueens(res, tmp, row + 1, n);
                tmp[row][col] = '.';
            }
        }
    }

    bool isvalid(vector<string> &tmp, int row, int col, int &n) {
        //chech column
        for (int i = 0; i < row; ++i)
            if (tmp[i][col] == 'Q')
                return false;

        //check 45
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (tmp[i][j] == 'Q')
                return false;

        //check 135
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (tmp[i][j] == 'Q')
                return false;
        return true;
    }
};
/**
  *    | | |                / / /             \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / /                 \ \ \
  *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
 */
class Solution_B {
public:
    /**
     *
     * @param n
     * @return
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, tmp, flag_col, flag_45, flag_135, 0, n);
        return res;
    }

private:
    void solveNQueens(vector<vector<string>> &res, vector<string> &tmp, vector<int> &flag_col,
                      vector<int> &flag_45, vector<int> &flag_135, int row, int &n) {
        if (row == n) {
            res.push_back(tmp);
            return;
        }
        for (int col = 0; col != n; ++col) {
            if (flag_col[row] && flag_45[row + col] && flag_135[n + row - col - 1]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                tmp[row][col] = 'Q';
                solveNQueens(res, tmp, flag_col, flag_45, flag_135, row + 1, n);
                tmp[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
        }
    }
};
class Solution_C {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        /*
        flag[0] to flag[n - 1] to indicate if the column had a queen before.
        flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
        flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
        */
        std::vector<int> flag(5 * n - 2, 1);
        solveNQueens(res, nQueens, flag, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag, row + 1, n);
                nQueens[row][col] = '.';
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
            }
    }
};