//
// Created by Maloney on 17-4-12.
//
#include <iostream>
using namespace std;
#ifndef LEETCODE_SOLUTION_3_H
#define LEETCODE_SOLUTION_3_H

#endif //LEETCODE_SOLUTION_3_H

/**
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring
 *       "pwke" is a subsequence and not a substring.
 */
class Solution_3 {
public:
    int lengthOfLongestSubstring(string s) {
        int length=s.length();
        int max;
        int start=0,size=1;
        int begin=0,end=length-1;
        int hash[24]={0};
        for(int i=i;i<length;++i){
            hash[s[start]-97]++;
            if(hash[s[i]]<1){//s[i]在start开始size长度里没出现过
                size++;
            }
            else{
                start=i;

            }
        }


        return 1;
    }
};
