//
// Created by Maloney on 17-4-16.
//
#include <iostream>
using namespace std;

#include <unordered_map>
#ifndef LEETCODE_SOLUTION_13_H
#define LEETCODE_SOLUTION_13_H

#endif //LEETCODE_SOLUTION_13_H
/**
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution_13 {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int len=s.length();
        int result=m[s[len-1]];
        for(int i=len-2;i>=0;--i){
            if(m[s[i]]>=m[s[i+1]])
                result+=m[s[i]];
            else
                result-=m[s[i]];
        }
        return result;
    }
};