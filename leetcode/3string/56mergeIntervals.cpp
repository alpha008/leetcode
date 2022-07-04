#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"helpvector.h"
using namespace std;
/****************************************************************************************
描述
Given a collection of intervals, merge all overlapping intervals.
For example, Given [1,3],[2,6],[8,10],[15,18], return [1,6],[8,10],[15,18]
分析
复用一下 Insert Intervals 的解法即可，创建一个新的 interval 集合，然后每次从旧的里面取一个
interval 出来，然后插入到新的集合中
*****************************************************************************************/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) { }
    Interval(int s, int e) : start(s), end(e) { }
};
//LeetCode, Merge Interval
//复用一下 Insert Intervals 的解法即可
// 时间复杂度 O(n1+n2+...)，空间复杂度 O(1)
class Solution {
public:
vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    for (int i = 0; i < intervals.size(); i++) {
        insert(result, intervals[i]);
    }
    return result;
}
private:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while (it != intervals.end()) {
            if (newInterval.end < it->start) {
                intervals.insert(it, newInterval);
                return intervals;
            } else if (newInterval.start > it->end) {
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
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));

    Solution ab;
    vector<Interval> result = ab.merge(intervals);
    for(int i = 0;  i < result.size() ; i++)
    {
        cout << "i: " << i << "  start: " <<  result[i].start << "  end:" << result[i].end << endl;
    }

    return 0;
}














