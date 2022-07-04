#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"helpvector.h"
using namespace std;
/****************************************************************************************
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary)
You may assume that the intervals were initially sorted according to their start times
Example 1: Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Example 2: 
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

is is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]
*****************************************************************************************/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) { }
    Interval(int s, int e) : start(s), end(e) { }
};
//LeetCode, Insert Interval
// 时间复杂度 O(n)，空间复杂度 O(1)
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while (it != intervals.end())
        {
            if (newInterval.end < it->start) {
                intervals.insert(it, newInterval);
                return intervals;
            }
            else if (newInterval.start > it->end) {
                it++;
                continue;
            } else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(6,9));
    for(int i = 0;  i < intervals.size() ; i++)
    {
        cout << "i: " << i << "  start: " <<  intervals[i].start << "  end:" << intervals[i].end << endl;
    }
    Interval newInsert(2,5);
    Solution ab;
    vector<Interval> result = ab.insert(intervals,newInsert);
    for(int i = 0;  i < result.size() ; i++)
    {
        cout << "i: " << i << "  start: " <<  result[i].start << "  end:" << result[i].end << endl;
    }

    return 0;
}
