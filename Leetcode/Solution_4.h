//
// Created by Maloney on 17-4-13.
//
#include <iostream>
using namespace std;
#include <vector>
#ifndef LEETCODE_SOLUTION_4_H
#define LEETCODE_SOLUTION_4_H

#endif //LEETCODE_SOLUTION_4_H
/**
 *There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 *nums1 = [1, 3]
 *nums2 = [2]
 *The median is 2.0
 */
class Solution_4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length_1=nums1.size();
        int length_2=nums2.size();
        int target=(length_1+length_2)/2;
        int flag=0;//1:取两个数第(target,target+1); 0:取第target+1
        if((length_1+length_2)%2==0)
            flag=1;
        //when (num1 or num2 is NULL)
        if(length_1==0&&length_2>0){
            if(flag){
                return (double)(nums2[target-1]+nums2[target])/2;
            }
            else
                return (double)nums2[target];
        }
        if(length_2==0&&length_1>0){
            if(flag)
                return (double)(nums1[target-1]+nums1[target])/2;
            else
                return (double)nums1[target];
        }

        if(flag){
            return (FindKth(nums1,length_1,nums2,length_2,target)+FindKth(nums1,length_1,nums2,length_2,target+1))/2;
        }
        else
            return FindKth(nums1,length_1,nums2,length_2,target+1);

    }
    double FindKth(vector<int>& nums1,int length_1, vector<int>& nums2,int length_2,int k){
        //用长度作为参数,减少stl计算.size()的次数,当然传参也是增加辅助空间的
        //同时,如果顾及通用性:把长度参数去掉,无伤大雅
        int p=0,q=0,count=0;
        double value;
        while(p<length_1||q<length_2){
            if(nums1[p]<nums2[q]){
                if(p<length_1){
                    value=nums1[p];
                    ++p;
                }
                else{
                    value=nums2[q];
                    ++q;
                }
            }
            else{
                if(q<length_2){
                    value=nums2[q];
                    ++q;
                }
                else{
                    value=nums1[p];
                    ++p;
                }
            }
            ++count;
            if(count==k)
                break;
        }
        return value;
    }
};