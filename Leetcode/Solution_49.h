//
// Created by Maloney on 17-6-6.
//
#include <iostream>
using namespace std;

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#ifndef LEETCODE_SOLUTION_49_H
#define LEETCODE_SOLUTION_49_H

#endif //LEETCODE_SOLUTION_49_H
/**
 * Group Anagrams
 * Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s:strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> res;
        for (auto m:mp) {
            vector<string> str(m.second.begin(), m.second.end());
            res.push_back(str);
        }
        return res;
    }
};
