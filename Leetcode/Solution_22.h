//
// Created by Maloney on 17-4-23.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_22_H
#define LEETCODE_SOLUTION_22_H

#endif //LEETCODE_SOLUTION_22_H

class Solution_22 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }

    void addingpar(vector<string> &v, string str, int n, int m) {
        if (n == 0 && m == 0) {
            v.push_back(str);
            return;
        }
        if (m > 0) { addingpar(v, str + ")", n, m - 1); }
        if (n > 0) { addingpar(v, str + "(", n - 1, m + 1); }
    }
};
