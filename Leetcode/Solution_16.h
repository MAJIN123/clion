//
// Created by Maloney on 17-4-19.
//
#include <iostream>
#include<vector>
using namespace std;
#include<algorithm>

#ifndef LEETCODE_SOLUTION_16_H
#define LEETCODE_SOLUTION_16_H

#endif //LEETCODE_SOLUTION_16_H
/**
 * Given an array S of n integers, find three integers in S
 * such that the sum is closest to a given number, target.
 * Return the sum of the three integers. You may assume
 * that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=0;
        while(1){
            if(threeSum(nums,target-n))
                return target-n;
            if(threeSum(nums,target+n))
                return target+n;
            ++n;
        }

    }
    bool threeSum(vector<int>& nums,int target){
        for(int i=0;i<nums.size();++i){
            int begin=i+1;
            int end=nums.size()-1;
            while(begin<end){
                if(nums[i]+nums[begin]+nums[end]<target)
                    ++begin;
                else if(nums[i]+nums[begin]+nums[end]>target)
                    --end;
                else
                    return true;
            }
        }
        return false;
    }
};