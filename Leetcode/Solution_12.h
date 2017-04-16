//
// Created by Maloney on 17-4-16.
//

#ifndef LEETCODE_SOLUTION_12_H
#define LEETCODE_SOLUTION_12_H
#include <iostream>
using namespace std;

#include <string>

#endif //LEETCODE_SOLUTION_12_H
/**
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
/*
罗马字符    I   V   X   L   C   D   M
整数数字    1   5   10  50  100 500 1000
相同的数字连写，所表示的数等于这些数字相加得到的数，如：III = 3；
小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：VIII = 8；XII = 12；
小的数字，（限于I、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：IV= 4；IX= 9；
正常使用时，连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）
 */

class Solution_12 {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];

    }
};