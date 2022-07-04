#include<iostream>
#include<vector>
using namespace std;
/********************************************************************************************
示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：
输入：s = "cbbd"
输出："bb"
最长回文子串，遍历字符串，以j结尾 ，然后i从头开始遍历判断
********************************************************************************************/
string longestPalindrome(string s) 
{
    // 初始化状态容器
    vector<vector<bool>> dp(s.size(),vector<bool>(s.size(), false));
    for(int i = 0; i < s.size();i ++)
    {
        dp[i][i] = true;
    }
    //记录
    size_t max_len = 1, start = 0; // 最长回文子串的长度，起点
    // dp[i][j]  记录的从第  i-j 是否是回文串 
    for (int j = 1; j < s.size(); j++)    // 以j结尾
    {
        for (int i = 0; i < j; i++)   // i开始位置肯定要小于j结束位置
        {                                       // [i, j]  0 1 2 3  |相邻  +   中间至少隔一个|
            dp[i][j] = (s[i] == s[j] && (j - i < 2  || dp[i + 1][j - 1])); // 位置相邻 或者子区间为回文串
            if (dp[i][j] && max_len < (j - i + 1)) 
            {
                max_len = j - i + 1;
                start = i;
            }
        }
    }
    // 返回结果
    return  s.substr(start,max_len);
}
// 最大回文子串
int main()
{
    string s = "babad";
    cout << "s:" << s << endl;    
    string res = longestPalindrome(s);
    cout << "res:" << res << endl;
    cout << "hello " << endl;
    return 0;
} 