//
// Created by Maloney on 17-7-6.

//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_68_H
#define LEETCODE_SOLUTION_68_H

#endif //LEETCODE_SOLUTION_68_H
/**
 *  Given an array of words and a length L, format the text such that each line has exactly
 *  L characters and is fully (left and right) justified.
 *  You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
 *  Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *  Extra spaces between words should be distributed as evenly as possible.
 *  If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 *  For the last line of text, it should be left justified and no extra space is inserted between words.
 *  For example,
 *  words: ["This", "is", "an", "example", "of", "text", "justification."]
 *  L: 16.
 *   Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
 */
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        for (int i = 0, k, l; i < words.size(); i += k) {
            for (k = l = 0; i + k < words.size() and l + k + words[i + k].size() <= maxWidth; k++)
                l += words[i + k].size();
            string tmp = words[i];
            for (int j = 0; j < k - 1; j++) {
                if ((i + k) >= words.size())
                    tmp += " ";
                else
                    tmp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');
                tmp += words[j + i + 1];
            }
            tmp += string(maxWidth - tmp.size(), ' ');
            res.push_back(tmp);
        }
        return res;
    }
};
