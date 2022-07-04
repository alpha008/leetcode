#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<deque>
#include "helpvector.h"
using namespace std;

//76. Minimum Window Substring  -- hard
//For example, S = ”ADOBECODEBANC”, T = ”ABC”
/***********************************************************************
expected_count[A] = 1 ;expected_count[B] = 1 ;expected_count[C] = 1
expected_count[] = ?  ;expected_count[] = ? ;expected_count[] = ? ;
************************************************************************/
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0) return "";
        if(s.size() < t.size() ) return "";

        // 记录匹配串
        const int ASCII_MAX = 256;
        vector<int> appeared_count(ASCII_MAX , 0);
        vector<int> expected_count(ASCII_MAX , 0 );
        for(int i = 0; i < t.size(); i++){
            expected_count[t[i]]++;
        }
        // 记录窗口大小以及起始位置
        int minWidth = INT32_MAX ;
        int min_start = 0;
        
        int wnd_start = 0;
        int appeared = 0;

        // 开始查找
        for(int wnd_end = 0; wnd_end < s.size() ; wnd_end++)
        {
            if(expected_count[s[wnd_end]] > 0){
                appeared_count[s[wnd_end]]++;    // 如果是期望出现的，那么就记录
                if(appeared_count[s[wnd_end] ] <= expected_count[s[wnd_end]])  // 如果是期望出现的，但是次数还不够，那么就存储一个
                    appeared++;
            }
            if(appeared == t.size())
            {// 开始缩小左窗口起始 位置  || 如果起始位置出现的次数超过期望，那么可以去掉一个 || 如果不是期望出现的那么也可以去掉
                while(appeared_count[s[wnd_start]] > expected_count[s[wnd_start]] || expected_count[s[wnd_start]] == 0 )
                {
                    appeared_count[s[wnd_start]]-- ;
                    wnd_start++;
                }

                if(minWidth >( wnd_end - wnd_start + 1))
                {
                    minWidth = wnd_end - wnd_start + 1;
                    min_start = wnd_start;
                }
            }
        }
        if(minWidth == INT32_MAX){
            return "";
        }else{
            return s.substr(min_start, minWidth);
        }

    }
};

int main()
{
    vector<int> result;
    string str1 = "pwwkew";

    string str2 = "ADOBECODEBANC";
    string target = "ABC";
    Solution ab;
    cout << "minWindow :" << ab.minWindow(str2,target) << endl;

    vec_print(result);

    return 0;
}


















//239. Sliding Window Maximum -- hard
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(nums.size() == 0)
        return nums;
    vector<int> result;
    deque<int> window;
    for(int i = 0; i < nums.size(); i++)
    {
        while(!window.empty() && nums[i] > nums[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);  //将自己加入队列要排名次

        if(!window.empty() && window.front() <= (i - k))   // 删除上一个窗口的
            window.pop_front();

        if(i >= k - 1)  //主要是为了约束刚开始k个元素组成的窗口
            result.push_back(nums[window.front()]);
    }
    return result;
}