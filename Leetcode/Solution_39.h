//
// Created by Maloney on 17-5-8.
//
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#ifndef LEETCODE_SOLUTION_39_H
#define LEETCODE_SOLUTION_39_H

#endif //LEETCODE_SOLUTION_39_H
/**
 *  Given a set of candidate numbers (C) (without duplicates) and a target number (T),
 *  find all unique combinations in C where the candidate numbers sums to T.
 *  The same repeated number may be chosen from C unlimited number of times.
 */
/*
 * A solution set is:
[
  [7],
  [2, 2, 3]
]
 */
class Solution_39 {
public:
    /**
     *  Combination Sum
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
            com.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, com, i);
            com.pop_back();
        }
    }
};
