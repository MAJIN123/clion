//
// Created by Maloney on 17-5-9.
//
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#ifndef LEETCODE_SOLUTION_40_H
#define LEETCODE_SOLUTION_40_H

#endif //LEETCODE_SOLUTION_40_H
class Solution_40 {
public:
    /**
     *  Combination Sum II
     * @param candidates
     * @param target
     * @return
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> com;
        combinationSum(candidates, target, res, com, 0);
        return res;
    }

private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &com, int begin) {
        if (!target) {
            res.push_back(com);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            if (i == begin || candidates[i] != candidates[i - 1]) {
                com.push_back(candidates[i]);
                combinationSum(candidates, target - candidates[i], res, com, i + 1);
                com.pop_back();
            }
        }
    }
};