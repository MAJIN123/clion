//
// Created by Maloney on 17-6-10.

//
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#ifndef LEETCODE_SOLUTION_56_H
#define LEETCODE_SOLUTION_56_H

#endif //LEETCODE_SOLUTION_56_H
/**
 * Definition for an interval.
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
/**
 * Merge Intervals
 * Given a collection of intervals, merge all overlapping intervals.
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */
class Solution_56 {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty())
            return {};
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > res.back().end)
                res.push_back(intervals[i]);
            else
                res.back().end = max(intervals[i].end, res.back().end);
        }
        return res;
    }
};
/**
 * Insert Interval
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */
class Solution_57 {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> p(intervals);
        p.push_back(newInterval);
        return merge(p);
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty())
            return {};
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > res.back().end)
                res.push_back(intervals[i]);
            else
                res.back().end = max(intervals[i].end, res.back().end);
        }
        return res;
    }
};
/**
  auto range = m.equal_range(4);

+---+---+---+---+---+---+---+---+---+
| 2 | 3 | 3 | 4 | 4 | 4 | 4 | 5 | 6 |    =:   m
+---+---+---+---+---+---+---+---+---+
            ^               ^
            |               |
       range.first    range.second
 */
class Solution_57_b {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        auto compare = [](const Interval &intv1, const Interval &intv2) { return intv1.end < intv2.start; };
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
        auto itr1 = range.first, itr2 = range.second;
        if (itr1 == itr2) {
            intervals.insert(itr1, newInterval);
        } else {
            itr2--;
            itr2->start = min(newInterval.start, itr1->start);
            itr2->end = max(newInterval.end, itr2->end);
            intervals.erase(itr1, itr2);
        }
        return intervals;
    }
};
/**
 * Length of Last Word
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example,
 * Given s = "Hello World",
 * return 5.
 */
class Solution_58 {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length() - 1;
        while (i >= 1 && s[i] == ' ')
            --i;
        for (i; i >= 0; --i) {
            if (s[i] == ' ')
                return len;
            ++len;
        }
        return len;
    }
};