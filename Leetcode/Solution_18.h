//
// Created by Maloney on 17-4-20.
//
#include <iostream>
#include<vector>
using namespace std;
#include<algorithm>
#ifndef LEETCODE_SOLUTION_18_H
#define LEETCODE_SOLUTION_18_H

#endif //LEETCODE_SOLUTION_18_H
/**
 * Given an array S of n integers, are there elements a, b, c, and d in S
 * such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 */
class Solution_18 {
public:
    /**
     * @param nums : a vector contains some int nums
     * @param target : a int value
     * @return
     */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)
            return vector<vector<int> >();
        sort(nums.begin(),nums.end());
        vector<int> num(nums);

        vector<vector<int> > result;
        for(int i=0;i<nums.size()-3;++i){//nums

            int tmp=num[0];
            num.erase(num.begin());

            vector<vector<int> > tmp_result=threeSum(num,target-tmp);
            int x=tmp_result.size();
            if(tmp_result.size()>0) {
                for (int j = 0; j < tmp_result.size(); ++j) {
                    tmp_result[j].insert(tmp_result[j].begin(),tmp);
                    result.push_back(tmp_result[j]);
                }
            }
            while(i<nums.size()-4&&nums[i]==nums[i+1]){
                num.erase(num.begin());
                ++i;
            }
        }
        return result;
    }
    vector<vector<int> > threeSum(vector<int >& nums,int target) {
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
                if(nums[i]+nums[end]+nums[begin]>target)
                    end--;
                else if(nums[i]+nums[end]+nums[begin]<target)
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
        cout<<target<<"   "<< result.size()<<endl;
        return result;
    }

};