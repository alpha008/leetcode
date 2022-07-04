#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<deque>
using namespace std;
/***********************************************************************************************
 * 示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
1. Longest Substring Without Repeating Characters --hard
***********************************************************************************************/
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
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {  //复杂度 o n
        unordered_set<int> dict;
        int rk = -1 , ans = 0;
        for(int i = 0; i < s.size() ;i ++)
        {
            if(i != 0)
                dict.erase(s[i - 1]);
            while(rk + 1 < s.size() && !dict.count(s[rk+1])){
                dict.insert(s[rk +1]);
                rk++;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
 string lengthOfLongestSubstring(string s) 
 {// 窗口:  以当前i位置结尾，之前没有重复的字符窗口
        int length = 0 ;
        int left = -1, right = 0;
        unordered_map<int, int> m;  // 哈希表用来缓存数据，如果前面没有，那么放入集合中
        for ( right = 0; right <  s.size(); ++right) { 
            // e[abcd]e  left = e  left记录的是窗口左边的位置
            if (m.count(s[right]) && m[s[right]] > left) {  // 说明当前字符出现了，并且在窗口内 
                cout << "right : " <<  right << " " << s[right]<< endl;
                left = m[s[right]];  // 更新窗口的起始位置
                cout << "left : " <<  left << endl;
            }
            m[s[right]] = right;   // 缓存数据
            length = max(length, right - left);            
        }
        return s.substr(left,length);
}
int maxSubStr(string & s)
{
    if(s.size() == 0 )
        return 0;
    unordered_set<char> lookup;
    int maxStr = 0;
    int left = 0;
    for(int i =  0; i < s.size() ;i++)
    {
        while (lookup.find(s[i]) != lookup.end())
        {
            lookup.erase(s[left]);
            left++;
        }
        maxStr = max(maxStr, i - left + 1);
        lookup.insert(s[i]);
    }
    return maxStr;
}
int main()
{
    string str1 = "abcad";
    //1.单个字符串内，最长的不包含重复字符的子串的长度
    lengthOfLongestSubstring(str1);
    //cout << "lengthOfLongestSubstring: " << maxSubStr(str1) << endl;
    return 0;
}
