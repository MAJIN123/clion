//
// Created by Maloney on 17-5-19.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_46_H
#define LEETCODE_SOLUTION_46_H

#endif //LEETCODE_SOLUTION_46_H
/**
 * Permutations
 */
class Solution_46 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int> > res;
        permute(nums, 0, res);
        return res;
    }
    void permute(vector<int> &nums, int begin, vector<vector<int> > &res) {
        if (begin >= nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]);
            permute(nums, begin + 1, res);
            swap(nums[begin], nums[i]);
        }
    }
};
