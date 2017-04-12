//
// Created by Maloney on 17-4-12.
//
#include <iostream>
#include<vector>
using namespace std;
#include<algorithm>

#ifndef LEETCODE_SOLUTION_15_H
#define LEETCODE_SOLUTION_15_H

#endif //LEETCODE_SOLUTION_15_H
//leetcode_15
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//[-1, 0, 1],
//[-1, -1, 2]
//]
class Solution_15 {
public:
    vector<vector<int> > threeSum(vector<int >& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        if(nums.size()<3)
            return result;
        for(int i=0;i<nums.size()-2;++i){
            int begin=i+1;
            int end=nums.size()-1;
            if(i>0&&(nums[i]==nums[i-1]))
                continue;
            while(begin<end){
                if(begin>i+1&&nums[begin]==nums[begin-1]){
                    begin++;
                    continue;
                }
                if(end<nums.size()-1&&nums[end]==nums[end+1]){
                    end--;
                    continue;
                }
                if(nums[i]+nums[end]+nums[begin]>0)
                    end--;
                else if(nums[i]+nums[end]+nums[begin]<0)
                    begin++;
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[begin]);
                    temp.push_back(nums[end]);
                    result.push_back(temp);
                    begin++;
                }
            }//end for while
        }//end for i
        return result;
    }
};