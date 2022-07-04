#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int left = -1, right = 0;
        unordered_map<int, int> indices;
        for(right  = 0; right < s.size(); right++)  // 只遍历一遍
        {
            if(( indices.count(s[right]) >0) &&( indices[s[right]] > left) )
                left = indices[s[right]];
            indices[s[right] ] = right;
            length = max(right - left   , length);
        }
        return length;
    }
};
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}