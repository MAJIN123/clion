//
// Created by Maloney on 17-5-15.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_ADD_KMP_H
#define LEETCODE_ADD_KMP_H

#endif //LEETCODE_ADD_KMP_H

class Solution_kmp{
public:
    vector<int> get_next(string s){
        int len=s.length();
        vector<int> next(len);
        next[0]=-1;
        int j=-1;
        int i=0;
        while(i<len){
            if(j==-1||s[j]==s[i])    {
                ++i;
                ++j;
                next[i]=j;
            }
            else
                j=next[j];
        }
        return next;
    }
    int KMP(string s,string p){
        vector<int> next=get_next(p);
        int i=0;
        int j=0;
        int slen=s.length();
        int plen=p.length();
        while(i<slen&&j<plen){
            if(j==-1||s[i]==p[j]){
                ++i;
                ++j;
            }
            else
                j=next[j];
        }
        if(j==plen)
            return i-j;
        else return -1;
    }
};