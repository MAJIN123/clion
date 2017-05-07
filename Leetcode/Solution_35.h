//
// Created by Maloney on 17-5-7.
//

#include <iostream>
using namespace std;

#include <vector>

#ifndef LEETCODE_SOLUTION_35_H
#define LEETCODE_SOLUTION_35_H

#endif //LEETCODE_SOLUTION_35_H

class Solution_35 {
public:
    /**
     * Search Insert Position
     * @param nums
     * @param target
     * @return
     */
    int searchInsert(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};