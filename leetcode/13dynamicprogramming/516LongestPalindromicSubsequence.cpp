#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
/************************************************************************************************************
动规五部曲分析如下：
1. 确定dp数组（dp table）以及下标的含义
    dp[i][j]：字符串s在[i, j]范围内最⻓的回⽂⼦序列的⻓度为dp[i][j]。
2. 确定递推公式
    在判断回⽂⼦串的题⽬中，关键逻辑就是看s[i]与s[j]是否相同。
    如果s[i]与s[j]相同，那么dp[i][j] = dp[i + 1][j - 1] + 2;
    （如果这⾥看不懂，回忆⼀下dp[i][j]的定义）
    如果s[i]与s[j]不相同，说明s[i]和s[j]的同时加⼊ 并不能增加[i,j]区间回⽂⼦串的⻓度，那么分别加⼊s[i]、
    s[j]看看哪⼀个可以组成最⻓的回⽂⼦序列。
    加⼊s[j]的回⽂⼦序列⻓度为dp[i + 1][j]。
    加⼊s[i]的回⽂⼦序列⻓度为dp[i][j - 1]。
    那么dp[i][j]⼀定是取最⼤的，即： dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
3. dp数组如何初始化
    ⾸先要考虑当i 和j 相同的情况，从递推公式： dp[i][j] = dp[i + 1][j - 1] + 2; 可以看出 递推公式是计算不
    到 i 和j相同时候的情况。
    所以需要⼿动初始化⼀下，当i与j相同，那么dp[i][j]⼀定是等于1的，即：⼀个字符的回⽂⼦序列⻓度就
    是1。
    其他情况dp[i][j]初始为0就⾏，这样递推公式： dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); 中dp[i][j]才不会被
    初始值覆盖。
4. 确定遍历顺序
    从递推公式dp[i][j] = dp[i + 1][j - 1] + 2 和 dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]) 可以看出， dp[i][j]是依
    赖于dp[i + 1][j - 1] 和 dp[i + 1][j]，
    也就是从矩阵的⻆度来说， dp[i][j] 下⼀⾏的数据。 所以遍历i的时候⼀定要从下到上遍历，这样才能保
    证，下⼀⾏的数据是经过计算的。
    递推公式： dp[i][j] = dp[i + 1][j - 1] + 2， dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]) 分别对应着下图中的红⾊
    箭头⽅向
示例 1:
输⼊: "bbbab"
输出: 4
⼀个可能的最⻓回⽂⼦序列为 "bbbb"。
示例 2:
输⼊:"cbbd"
输出: 2
⼀个可能的最⻓回⽂⼦序列为 "bb"。
***********************************************************************************************************/
class Solution {
public:
    int longestPalindromeSubseq(const string s)
    {
        int result = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        for(int i = 0; i < s.size(); i++) dp[i][i] = 1;

        for(int i = s.size()- 1; i >=0; i--)
        {
            for(int j = i+1; j < s.size(); j++)
            {
                if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};

int main()
{
    string s = "bbbab";


    cout << "hello " << endl;
    return 0;
}