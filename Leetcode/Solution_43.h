//
// Created by Maloney on 17-5-11.
//
#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>
#ifndef LEETCODE_SOLUTION_43_H
#define LEETCODE_SOLUTION_43_H

#endif //LEETCODE_SOLUTION_43_H
/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
 * Note:
    The length of both num1 and num2 is < 110.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */
class Solution_43 {
public:
    /**
     * Multiply Strings
     * @param num1
     * @param num2
     * @return
     */
    string multiply(string num1, string num2) {
        int size_of_nums1 = num1.size();
        int size_of_nums2 = num2.size();
        if (size_of_nums1 == 0 || size_of_nums2 == 0)
            return "0";
        vector<int> v(size_of_nums1 + size_of_nums2, 0);
        for (int i = 0; i < size_of_nums1; ++i) {
            int flag = 0;
            int n1 = (int) (num1[size_of_nums1 - 1 - i] - '0');
            for (int j = 0; j < size_of_nums2; ++j) {
                int n2 = (int) (num2[size_of_nums2 - 1 - j] - '0');

                int sum = n1 * n2 + flag + v[i + j];
                flag = sum / 10;
                v[i + j] = sum % 10;
            }
            if (flag)
                v[i + size_of_nums2] += flag;
        }
        int start = size_of_nums1 + size_of_nums2 - 1;
        while (v[start] == 0)start--;
        if (start < 0)return "0";

        string res = "";
        for (int i = start; i >= 0; --i)
            res += (char) (v[i] + '0');

        return res;
    }

    string another(string nums1, string nums2) {
        string res(nums1.size() + nums2.size(), '0');
        for (int i = nums1.size() - 1; i >= 0; --i) {
            int flag = 0;
            for (int j = nums2.size() - 1; j >= 0; --j) {
                int tmp = (res[i + j - 1] - '0') + (nums1[i] - '0') * (nums2[j] - '0') + flag;
                flag = tmp / 10;
                res[i + j - 1] = tmp % 10 + '0';
            }
            res[i] += flag;
        }
        size_t index = res.find_first_not_of('0');
        if (string::npos != index)
            return res.substr(index);
        return "0";

    }

};