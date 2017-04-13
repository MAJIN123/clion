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
        if(s.length()==0)
            return 0;
        int max=1;
        int start=0,size=1;
        bool flag;
        int x;

        for(int i=1;i<s.length();++i){
            flag=0;x=1;
           for(int j=start;j<size+start;++j){
               if(s[j]==s[i]){//出现过
                   x=j-start;
                   start=j+1;
                   flag=1;
                   break;
               }
           }//end for j
            if(!flag)
                size+=1;
            else
                size-=x;
            max=max>size?max:size;
        }//end for i

        return max;
    }
};
