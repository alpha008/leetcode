#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定两个字符串 text1 和 text2，返回这两个字符串的最⻓公共⼦序列的⻓度。
⼀个字符串的 ⼦序列 是指这样⼀个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除
某些字符（也可以不删除任何字符）后组成的新字符串。
例如， "ace" 是 "abcde" 的⼦序列，但 "aec" 不是 "abcde" 的⼦序列。两个字符串的「公共⼦序列」是
这两个字符串所共同拥有的⼦序列。
若这两个字符串没有公共⼦序列，则返回 0。
示例 1:
输⼊： text1 = "abcde", text2 = "ace"
输出： 3
解释：最⻓公共⼦序列是 "ace"，它的⻓度为 3。
示例 2:
输⼊： text1 = "abc", text2 = "abc"
输出： 3
解释：最⻓公共⼦序列是 "abc"，它的⻓度为 3。
示例 3:
输⼊： text1 = "abc", text2 = "def"
输出： 0
解释：两个字符串没有公共⼦序列，返回 0。
1. 确定dp数组（dp table）以及下标的含义
dp[i][j]：⻓度为[0, i - 1]的字符串text1与⻓度为[0, j - 1]的字符串text2的最⻓公共⼦序列为dp[i][j]
有同学会问：为什么要定义⻓度为[0, i - 1]的字符串text1，定义为⻓度为[0, i]的字符串text1不⾹么？
这样定义是为了后⾯代码实现⽅便，如果⾮要定义为为⻓度为[0, i]的字符串text1也可以，⼤家可以试⼀
试！
2. 确定递推公式
主要就是两⼤情况： text1[i - 1] 与 text2[j - 1]相同， text1[i - 1] 与 text2[j - 1]不相同
如果text1[i - 1] 与 text2[j - 1]相同，那么找到了⼀个公共元素，所以dp[i][j] = dp[i - 1][j - 1] + 1;
如果text1[i - 1] 与 text2[j - 1]不相同，那就看看text1[0, i - 2]与text2[0, j - 1]的最⻓公共⼦序列 和
text1[0, i - 1]与text2[0, j - 2]的最⻓公共⼦序列，取最⼤的。
即： dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
代码如下：
3. dp数组如何初始化
先看看dp[i][0]应该是多少呢？
test1[0, i-1]和空串的最⻓公共⼦序列⾃然是0，所以dp[i][0] = 0;
同理dp[0][j]也是0。
其他下标都是随着递推公式逐步覆盖，初始为多少都可以，那么就统⼀初始为0。
代码：
4. 确定遍历顺序
1. 确定dp数组（dp table）以及下标的含义
dp[i][j]：⻓度为[0, i - 1]的字符串text1与⻓度为[0, j - 1]的字符串text2的最⻓公共⼦序列为dp[i][j]
有同学会问：为什么要定义⻓度为[0, i - 1]的字符串text1，定义为⻓度为[0, i]的字符串text1不⾹么？
这样定义是为了后⾯代码实现⽅便，如果⾮要定义为为⻓度为[0, i]的字符串text1也可以，⼤家可以试⼀
试！
2. 确定递推公式
主要就是两⼤情况： text1[i - 1] 与 text2[j - 1]相同， text1[i - 1] 与 text2[j - 1]不相同
如果text1[i - 1] 与 text2[j - 1]相同，那么找到了⼀个公共元素，所以dp[i][j] = dp[i - 1][j - 1] + 1;
如果text1[i - 1] 与 text2[j - 1]不相同，那就看看text1[0, i - 2]与text2[0, j - 1]的最⻓公共⼦序列 和
text1[0, i - 1]与text2[0, j - 2]的最⻓公共⼦序列，取最⼤的。
即： dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
代码如下：
3. dp数组如何初始化
先看看dp[i][0]应该是多少呢？
test1[0, i-1]和空串的最⻓公共⼦序列⾃然是0，所以dp[i][0] = 0;
同理dp[0][j]也是0。
其他下标都是随着递推公式逐步覆盖，初始为多少都可以，那么就统⼀初始为0。
代码：
4. 确定遍历顺序
dp[i-1][j-1]  dp[i-1][j]
dp[i][j-1]    dp[i][j]
*/

class Solution {
public:
    int longestCommonSubsequence(string text1 ,string text2)
    {
        // 1. 二维数组 初始化状态容器
        vector<vector<int>> dp(text1.size() +1 , vector<int>(text2.size() +1,0) );
        // 2. 开始处理状态
        for(int i = 1; i <= text1.size() ; i++)
        {
            for(int j = 1; j <= text2.size(); j++)
            {
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
int main()
{
    string s1 = "abcde";
    string s2 = "ace";

    cout << "hello " << endl;
    return 0;
}