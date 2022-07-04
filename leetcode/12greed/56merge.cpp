#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/******************************************************************************
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
示例：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*********************************************************************************/
class Solution {
public:
// 按照区间左边界从⼩到⼤排序
    static bool cmp (const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), cmp);
        bool flag = false; // 标记最后⼀个区间有没有合并
        int length = intervals.size();
        for (int i = 1; i < length; i++) {
            int start = intervals[i - 1][0]; // 初始为i-1区间的左边界
            int end = intervals[i - 1][1]; // 初始i-1区间的右边界
            while (i < length && intervals[i][0] <= end) { // 合并区间
                end = max(end, intervals[i][1]); // 不断更新右区间
                if (i == length - 1) flag = true; // 最后⼀个区间也合并了
                i++; // 继续合并下⼀个区间
            }
            // start和end是表示intervals[i - 1]的左边界右边界，所以最优intervals[i]区间是否合并了要标记⼀下
            result.push_back({start, end});
        }
        // 如果最后⼀个区间没有合并，将其加⼊result
        if (flag == false) {
            result.push_back({intervals[length - 1][0], intervals[length - 1][1]});
        }
        return result;
    }
};
int main()
{   
    vector<int> nums = {1,2,5};
    int target = 11;
    Solution ab;

    cout << "hello " << endl;
    return 0;
}
