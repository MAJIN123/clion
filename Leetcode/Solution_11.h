//
// Created by Maloney on 17-4-16.
//
#include <iostream>
using namespace std;

#include <vector>

#ifndef LEETCODE_SOLUTION_11_H
#define LEETCODE_SOLUTION_11_H

#endif //LEETCODE_SOLUTION_11_H
/**
 * Given n non-negative integers a1, a2, ..., an,
 * where each represents a point at coordinate (i, ai).
 */

class Solution_11 {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int result=0;
        while(l<r){
            result=max(result,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r])
                l++;
            else
                --r;
        }

    }
};
