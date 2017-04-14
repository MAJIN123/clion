//
// Created by Maloney on 17-4-14.
//
#include <iostream>
using namespace std;
#include<string>
#include <algorithm>

#ifndef LEETCODE_SOLUTION_5_H
#define LEETCODE_SOLUTION_5_H

#endif //LEETCODE_SOLUTION_5_H
/**
 * Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 */
class Solution_5 {
public:
    string longestPalindrome_my(string s) {
        int length=s.length();
        if(length<2)
            return s;
        int max_size=1,max_begin;

        int begin,end;
        int flag=0;//flag==1:匹配不成功

        for(int i=0;i<length;++i){
            for(int j=length-1;j>i;--j){
                flag=0;
                begin=i;end=j;
                while(begin<end){
                    if(s[begin]!=s[end]){
                        flag=1;
                        break;
                    }
                    ++begin;
                    --end;
                }
                if(flag==0){
                    if(j-i+1>max_size){
                        max_size=j-i+1;
                        max_begin=i;
                    }
                    else
                        break;
                }
            }
        }//end for i
    return s.substr(max_begin,max_size);;
    }
    //思想就是循环遍历string,遍历到哪就将那个元素当做中间元素向两边拓展(就是找到s[i]为中心的回文字符串)
    //遇到重复 ++right,start=right+1;
    string longestPalindrome_InterNet(string s) {
        int length=s.length();
        if(length<2)
            return s;
        int max_len=1,max_left=0,left,right;

        for(int start=0;start<length&&length-start>max_len/2;){
            left=right=start;
            while(right<length-1&&s[right]==s[right+1])
                ++right;
            start=right+1;//表示for循环里面的最后的变化
            while(left>0&&right<length-1&&s[left-1]==s[right+1]){
                ++right;--left;
            }
            if(max_len<right-left+1){
                max_len=right-left+1;
                max_left=left;
            }
        }
        return s.substr(max_left,max_len);
    }
};