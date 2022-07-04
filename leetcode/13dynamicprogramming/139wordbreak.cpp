#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include"helpvector.h"
using namespace std;

/******************************************************************************
拆分时可以重复使⽤字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：
输⼊: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：
输⼊: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
注意你可以重复使⽤字典中的单词。
示例 3：
输⼊: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

单词就是物品，字符串s就是背包，单词能否组成字符串s，就是问物品能不能把背包装满。
拆分时可以重复使⽤字典中的单词，说明就是⼀个完全背包！
动规五部曲分析如下：
1. 确定dp数组以及下标的含义
    dp[i] : 字符串⻓度为i的话， dp[i]为true，表示可以拆分为⼀个或多个在字典中出现的单词。
2. 确定递推公式
    如果确定dp[j] 是true，且 [j, i] 这个区间的⼦串出现在字典⾥，那么dp[i]⼀定是true。（j < i ）。
    所以递推公式是 if([j, i] 这个区间的⼦串出现在字典⾥ && dp[j]是true) 那么 dp[i] = true。
3. dp数组如何初始化
    从递归公式中可以看出， dp[i] 的状态依靠 dp[j]是否为true，那么dp[0]就是递归的根基， dp[0]⼀定要为true，否则递归下去后⾯都都是false了。
    那么dp[0]有没有意义呢？dp[0]表示如果字符串为空的话，说明出现在字典⾥。
    但题⽬中说了“给定⼀个⾮空字符串 s” 所以测试数据中不会出现i为0的情况，那么dp[0]初始为true完全就是为了推导公式。
    下标⾮0的dp[i]初始化为false，只要没有被覆盖说明都是不可拆分为⼀个或多个在字典中出现的单词。
4. 确定遍历顺序
    题⽬中说是拆分为⼀个或多个在字典中出现的单词，所以这是完全背包。
    还要讨论两层for循环的前后循序。
    如果求组合数就是外层for循环遍历物品，内层for遍历背包。
    如果求排列数就是外层for遍历背包，内层for循环遍历物品。
    对这个结论还有疑问的同学可以看这篇本周⼩结！（动态规划系列五） ，这篇本周⼩节中，我做了如下
    总结：
    求组合数： 动态规划： 518.零钱兑换II
    求排列数： 动态规划： 377. 组合总和 Ⅳ、 动态规划： 70. 爬楼梯进阶版（完全背包）
    求最⼩数： 动态规划： 322. 零钱兑换、 动态规划： 279.完全平⽅数
本题最终要求的是是否都出现过，所以对出现单词集合⾥的元素是组合还是排列，并不在意！
那么本题使⽤求排列的⽅式，还是求组合的⽅式都可以。
即：外层for循环遍历物品，内层for遍历背包 或者 外层for遍历背包，内层for循环遍历物品 都是可以的。
    但本题还有特殊性，因为是要求⼦串，最好是遍历背包放在外循环，将遍历物品放在内循环。
如果要是外层for循环遍历物品，内层for遍历背包，就需要把所有的⼦串都预先放在⼀个容器⾥。（如
果不理解的话，可以⾃⼰尝试这么写⼀写就理解了）
所以最终我选择的遍历顺序为：遍历背包放在外循环，将遍历物品放在内循环。内循环从前到后。
5. 举例推导dp[i]
以输⼊: s = "leetcode", wordDict = ["leet", "code"]为例， dp状态如图：

*********************************************************************************/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++)  //遍历背包
        {
            /*如果确定dp[j] 是true，且 [j, i] 这个区间的⼦串出现在字典⾥，那么dp[i]⼀定是true。（j < i ）。
            所以递推公式是 if([j, i] 这个区间的⼦串出现在字典⾥ && dp[j]是true) 
            那么 dp[i] = true*/
            for(int j = 0; j < i;j ++)  // 遍历物品
            {
                string word = s.substr(j, i - j);  // 起始位置 + 截取个数    
                if(wordset.find(word) != wordset.end() && dp[j])  // 0 - j,  j -i  以j进行分割，i结尾的字符串  当dp[j]为真，且j-i为真 
                {
                    dp[i] = true;
                // cout << "i:" << i << " str: " << word << " " << endl;
                }
            }
        }
        /*cout << "dp " ;
        for(int i = 0; i < dp.size() ; i++)
        {
            cout << " " << dp[i] << " " ;
        }
        cout << endl;*/
        return dp[s.size()];
    }
};
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.size() + 1, false);
    unordered_set<string> wordset(wordDict.begin(), wordDict.end());
    dp[0] = true;
    for(int i = 1; i <= s.size(); i++)  //遍历背包
    {
        /*如果确定dp[j] 是true，且 [j, i] 这个区间的⼦串出现在字典⾥，那么dp[i]⼀定是true。（j < i ）。
        所以递推公式是 if([j, i] 这个区间的⼦串出现在字典⾥ && dp[j]是true) 
        那么 dp[i] = true*/
        for(int j = 0; j < i;j ++)  // 遍历物品
        {
            string word = s.substr(j, i - j);  // 起始位置 + 截取个数    
            if(wordset.find(word) != wordset.end() && dp[j])  // 0 - j,  j -i  以j进行分割，i结尾的字符串  当dp[j]为真，且j-i为真 
            {
                dp[i] = true;
               // cout << "i:" << i << " str: " << word << " " << endl;
            }
        }
    }
    /*cout << "dp " ;
    for(int i = 0; i < dp.size() ; i++)
    {
        cout << " " << dp[i] << " " ;
    }
    cout << endl;*/
    return dp[s.size()];
}

int main()
{   
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool res = wordBreak(s,wordDict);
    cout << "res is " << res << endl;
    cout << "hello " << endl;
    return 0;
}
