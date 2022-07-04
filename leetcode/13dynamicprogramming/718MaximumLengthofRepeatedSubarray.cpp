#include<iostream>
#include<vector>
#include<algorithm>
#include"helpvector.h"
using namespace std;

/******************************************************************************************************
  输⼊：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出： 3
解释：
⻓度最⻓的公共⼦数组是 [3, 2, 1] 
1. 确定dp数组（dp table）以及下标的含义
dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最⻓重复⼦数组⻓度为dp[i][j]。
此时细⼼的同学应该发现，那dp[0][0]是什么含义呢？总不能是以下标-1为结尾的A数组吧。
其实dp[i][j]的定义也就决定着，我们在遍历dp[i][j]的时候i 和 j都要从1开始。
那有同学问了，我就定义dp[i][j]为 以下标i为结尾的A，和以下标j 为结尾的B，最⻓重复⼦数组⻓度。不⾏么？
⾏倒是⾏！ 但实现起来就麻烦⼀点，⼤家看下⾯的dp数组状态图就明⽩了。
2. 确定递推公式
根据dp[i][j]的定义， dp[i][j]的状态只能由dp[i - 1][j - 1]推导出来。
即当A[i - 1] 和B[j - 1]相等的时候， dp[i][j] = dp[i - 1][j - 1] + 1;
根据递推公式可以看出，遍历i 和 j 要从1开始！
3. dp数组如何初始化
根据dp[i][j]的定义， dp[i][0] 和dp[0][j]其实都是没有意义的！
但dp[i][0] 和dp[0][j]要初始值，因为 为了⽅便递归公式dp[i][j] = dp[i - 1][j - 1] + 1;
所以dp[i][0] 和dp[0][j]初始化为0。
举个例⼦A[0]如果和B[0]相同的话， dp[1][1] = dp[0][0] + 1，只有dp[0][0]初始为0，正好符合递推公式
逐步累加起来。
4. 确定遍历顺序
外层for循环遍历A，内层for循环遍历B。那⼜有同学问了，外层for循环遍历B，内层for循环遍历A。不⾏么？
也⾏，⼀样的，我这⾥就⽤外层for循环遍历A，内层for循环遍历B了。
同时题⽬要求⻓度最⻓的⼦数组的⻓度。所以在遍历的时候顺便把dp[i][j]的最⼤值记录下来
******************************************************************************************************/
class Solution {
public:
    int findLength(vector<int> &numsa, vector<int> &numsb)
    {
        int result = 0;
        vector<vector<int>>dp(numsa.size() + 1,vector<int>(numsb.size() + 1, 0));
        for(int i = 1; i <= numsa.size() ;i++ )
        {
            for(int j = 1; j <= numsb.size() ;j++)
            {
                if(numsa[i-1] == numsb[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                if(dp[i][j] > result) result = dp[i][j];
            }
        }

        return result;
    }
};
int main()
{
    vector<int> numsa = {1,2,3,2,1};
    vector<int> numsb = {3,2,1,4,7};
    Solution ab;
    cout << "res is " <<ab.findLength(numsa,numsb) << endl;
    cout << "  hello " << endl;
    return 0;
}