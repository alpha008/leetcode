#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*****************************************************************************************
给定字符串 s 和 t ，判断 s 是否为 t 的⼦序列。
字符串的⼀个⼦序列是原始字符串删除⼀些（也可以不删除）字符⽽不改变剩余字符相对位置形成的新
字符串。（例如， "ace"是"abcde"的⼀个⼦序列，⽽"aec"不是）。
示例 1：
输⼊： s = "abc", t = "ahbgdc"
输出： true
示例 2：
输⼊： s = "axc", t = "ahbgdc"
输出： false
1. 确定dp数组（dp table）以及下标的含义
    dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同⼦序列的⻓度为dp[i][j]。
    注意这⾥是判断s是否为t的⼦序列。即t的⻓度是⼤于等于s的。
2. 确定递推公式
    在确定递推公式的时候，⾸先要考虑如下两种操作，整理如下：
    if (s[i - 1] == t[j - 1])
    t中找到了⼀个字符在s中也出现了
    if (s[i - 1] != t[j - 1])
    相当于t要删除元素，继续匹配

    if (s[i - 1] == t[j - 1])，那么dp[i][j] = dp[i - 1][j - 1] + 1;，因为找到了⼀个相同的字符，相同⼦序列⻓度⾃
    然要在dp[i-1][j-1]的基础上加1（如果不理解，在回看⼀下dp[i][j]的定义）

    if (s[i - 1] != t[j - 1])，此时相当于t要删除元素， t如果把当前元素t[j - 1]删除，那么dp[i][j] 的数值就是 看
    s[i - 1]与 t[j - 2]的⽐较结果了，即： dp[i][j] = dp[i][j - 1];
3. dp数组如何初始化
    从递推公式可以看出dp[i][j]都是依赖于dp[i - 1][j - 1] 和 dp[i][j - 1]，所以dp[0][0]和dp[i][0]是⼀定要初始化的。

    这⾥⼤家已经可以发现，
    在定义dp[i][j]含义的时候为什么要表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同⼦序列的⻓度为dp[i][j]
*********************************************************************************************/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() +1, vector<int>(t.size()+1, 0));
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= t.size(); j++)
            {
                if(s[ i - 1] == t[j - 1]){
                    dp[i][j] = dp[i -1][j -1] + 1;
                }else{
                    dp[i][j] = dp[i][j -1];
                }
            }
        }
        if(dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};
int main()
{
    string s1 = "abc";
    string s2 = "ahbgdc";  // 判断s1 是否是s2的子串
    Solution ab;
    bool res = ab.isSubsequence(s1, s2);
    cout << "res is " << res << endl;
    cout << "hello " << endl;
    return 0;
}