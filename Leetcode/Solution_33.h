//
// Created by Maloney on 17-5-6.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_33_H
#define LEETCODE_SOLUTION_33_H

#endif //LEETCODE_SOLUTION_33_H

class Solution_33 {
public:
    /**
     * Search in Rotated Sorted Array
     * @param nums
     * @param target
     * @return
     */
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        int root = l;
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int relmid = (mid + root) % nums.size();
            if (nums[relmid] == target)return relmid;
            if (nums[relmid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};