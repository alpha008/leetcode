
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<limits.h>
#include<string>
#include<unordered_map>
#include"helpvector.h"
using namespace std;
/***********************************************************************************************
386. Longest Substring with At Most K Distinct Characters
给定一个字符串，求它的最长子串，这个子串最多只能有K个不同的字符。跟上题类似，只不过要把HashSet换成HashMap了。
样例 1:
输入: S = "eceba" 并且 k = 3
输出: 4
解释: T = "eceb"
样例 2:
输入: S = "WORLD" 并且 k = 4
输出: 4
解释: T = "WORL" 或 "ORLD"
***********************************************************************************************/
int lengthOfLongestSubstringKDistinct(string s, int k) {
    int res = 0, left = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); ++i) {
        ++m[s[i]];             //统计s[i]出现的次数
        while (m.size() > k) {
            if (--m[s[left]] == 0) 
                m.erase(s[left]);
            ++left;
        }
        res = max(res, i - left + 1);
    }
    return res;
}

int main()
{
    string s = "eceba";
    int k = 3;
    cout << "s: " << s << endl;
    int res = lengthOfLongestSubstringKDistinct(s,k);
    cout << "res is " << res << endl;
    return 0;
}
