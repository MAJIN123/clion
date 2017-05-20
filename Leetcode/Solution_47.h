//
// Created by Maloney on 17-5-19.
//
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

#ifndef LEETCODE_SOLUTION_47_H
#define LEETCODE_SOLUTION_47_H

#endif //LEETCODE_SOLUTION_47_H
/**
 * Permutations II
 * [1,1,2] have the following unique permutations:
 [
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */
class Solution_47 {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        permute(nums, 0, res);
        return res;
    }

    void permute(vector<int> nums, int begin, vector<vector<int> > &res) {
        if (begin == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            if (i!=begin&&nums[i] == nums[begin])continue;
            swap(nums[begin], nums[i]);
            permute(nums, begin + 1, res);
        }
    }
};