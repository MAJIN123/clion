//
// Created by Maloney on 17-4-19.
//
#include <iostream>
using namespace std;

#include <vector>
#include <unordered_map>
#ifndef LEETCODE_SOLUTION_17_H
#define LEETCODE_SOLUTION_17_H

#endif //LEETCODE_SOLUTION_17_H
/**
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 */
class Solution_17 {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return vector<string>();
        vector<string> result;
        const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");

        for (int i = 0; i < digits.size(); ++i) {
            int count = 0;
            ++count;
            cout << count << "  ";
            int num = digits[i] - '0';
            if (num < 0 && num > 9)
                break;
            string str = v[num];
            if (str.empty())
                continue;
            vector<string> tmp;//对于每次的i循环,tmp为NULL
            for (int p = 0; p < str.size(); ++p)
                for (int q = 0; q < result.size(); ++q)
                    tmp.push_back(result[q] + str[p]);
            result.swap(tmp);
        }
        return result;
    }
};
