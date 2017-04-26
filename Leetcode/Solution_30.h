//
// Created by Maloney on 17-4-24.
//
#include <iostream>
using namespace std;

#include <vector>
#include <unordered_map>
#ifndef LEETCODE_SOLUTION_30_H
#define LEETCODE_SOLUTION_30_H

#endif //LEETCODE_SOLUTION_30_H
/**
 * Substring with Concatenation of All Words
 * s: "barfoothefoobarman"  words: ["foo", "bar"]
 * You should return the indices: [0,9].
 */
class Solution_30 {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (s.empty() || words.size() == 0 || s.size() < words.size() * words[0].size())
            return vector<int>();
        int size_OfWords = words.size();
        int size_OfOneWord = words[0].size();
        int size = size_OfWords * size_OfOneWord;
        unordered_map<string, int> p;
        for (string str:words)
            ++p[str];

        vector<int> result;
        bool flag = 0;
        for (int i = 0; i <= s.size() - size; ++i) {
            flag = 0;
            unordered_map<string, int> q(p);
            for (int j = 0; j < size_OfWords; ++j) {
                string str = s.substr(i + j * size_OfOneWord, size_OfOneWord);
                if (q[str])
                    q[str] -= 1;
                else {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                result.push_back(i);
        }
        return result;
    }
};
