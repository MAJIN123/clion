//
// Created by Maloney on 17-4-12.
//
#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;
#ifndef LEETCODE_SOLUTION_1_H
#define LEETCODE_SOLUTION_1_H

#endif //LEETCODE_SOLUTION_1_H
//leetcode_1
//Given nums = [2, 7, 11, 15], target = 9,
//
//        Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
class Solution_1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int>res;
        for(int i=0;i<nums.size();++i) {
            if (res.find(target - nums[i]) == res.end()) {
                res.insert(pair<int, int>(nums[i], i));
            }
            else if (i != res[target - nums[i]]) {
                result.push_back(res[target - nums[i]]);
                result.push_back(i);
                return result;
            }
        }
    }
};
