//
// Created by Maloney on 17-4-16.
//
#include <iostream>
using namespace std;

#include <vector>
#include <string>

#ifndef LEETCODE_SOLUTION_14_H
#define LEETCODE_SOLUTION_14_H

#endif //LEETCODE_SOLUTION_14_H
/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
class Solution_14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=strs.size();
        string result="";
        if(len==0)
            return result;
        for(int i=0;;++i){
            for(int j=0;j<len;++j)
                if(i>strs[j].size()||strs[0][i]!=strs[j][i])
                    return result;
            result+=strs[0][i];
        }
    }
};