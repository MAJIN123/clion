//
// Created by Maloney on 17-5-7.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_36_H
#define LEETCODE_SOLUTION_36_H

#endif //LEETCODE_SOLUTION_36_H

class Solution_36 {
public:
    /**
     * Valid Sudoku
     * @param board
     * @return
     */
    bool isValidSudoku(vector<vector<char>> &board) {
        int flag_row[9][9] = {0};
        int flag_col[9][9] = {0};
        int flag_sub[9][9] = {0};
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if (flag_col[i][num] || flag_row[j][num] || flag_sub[k][num])
                        return false;
                    flag_col[i][num] = flag_row[j][num] = flag_sub[k][num] = 1;
                }
            }
        return true;
    }
};