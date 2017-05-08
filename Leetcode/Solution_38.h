//
// Created by Maloney on 17-5-8.
//
#include <iostream>
using namespace std;

#include <vector>

#ifndef LEETCODE_SOLUTION_38_H
#define LEETCODE_SOLUTION_38_H

#endif //LEETCODE_SOLUTION_38_H

/**
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 */
class Solution_38 {
public:
    /**
     * Count and Say
     * @param n
     * @return
     */
    string countAndSay(int n) {
        if(n==0)
            return "";
        string res="1";
        while(--n){
            string cur="";
            for(int i=0;i<res.size();++i){
                int count=1;
                while(i+1<res.size()&&res[i]==res[i+1]){
                    count++;i++;
                }
                cur+=to_string(count)+res[i];
            }
            res=cur;
        }
        return res;
    }
    int Strtoint(string a){
        int rel=0;
        for(int i=0;i<a.size();++i){
            int tmp=a[i]-'0';
            rel=rel*10+tmp;
        }
        return rel;
    }
    /**
     * 21 is read off as "one 2, then one 1" or 1211.
     * @param n
     * @return
     */
    string js(int n){
        string rel="";
        vector<int> p;
        while(n>0){
            int a=n%10;
            p.push_back(n%10);//取最后
            n=n/10;
        }
        int num=*(p.end()-1),count=0;
        while(p.size()>0){
            int tmp=*(p.end()-1);
            p.pop_back();
            if(tmp==num)
                count++;
            else{
                rel+=char(count+'0');
                rel+=char(num+'0');
                num=tmp;
                count=1;
            }
        }
        rel+=char(count+'0');
        rel+=char(num+'0');
        return rel;
    }
};