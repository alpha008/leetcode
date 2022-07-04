#include<iostream>
#include<vector>
#include<algorithm>
#include"helpvector.h"
using namespace std;
/*******************************************************************************************
1. 确定dp数组（dp table）以及下标的含义
dp[i]：包括下标i之前的最⼤连续⼦序列和为dp[i]。
2. 确定递推公式
dp[i]只有两个⽅向可以推出来：
dp[i - 1] + nums[i]，即： nums[i]加⼊当前连续⼦序列和
nums[i]，即：从头开始计算当前连续⼦序列和
⼀定是取最⼤的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);
3. dp数组如何初始化
从递推公式可以看出来dp[i]是依赖于dp[i - 1]的状态， dp[0]就是递推公式的基础。
dp[0]应该是多少呢?
更具dp[i]的定义，很明显dp[0]因为为nums[0]即dp[0] = nums[0]。
4. 确定遍历顺序
递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历。
5. 举例推导dp数组1. 确定dp数组（dp table）以及下标的含义
dp[i]：包括下标i之前的最⼤连续⼦序列和为dp[i]。
2. 确定递推公式
dp[i]只有两个⽅向可以推出来：
dp[i - 1] + nums[i]，即： nums[i]加⼊当前连续⼦序列和
nums[i]，即：从头开始计算当前连续⼦序列和
⼀定是取最⼤的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);
3. dp数组如何初始化
从递推公式可以看出来dp[i]是依赖于dp[i - 1]的状态， dp[0]就是递推公式的基础。
dp[0]应该是多少呢?
更具dp[i]的定义，很明显dp[0]因为为nums[0]即dp[0] = nums[0]。
4. 确定遍历顺序
递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历。
5. 举例推导dp数组
在回顾⼀下dp[i]的定义：包括下标i之前的最⼤连续⼦序列和为dp[i]。
那么我们要找最⼤的连续⼦序列，就应该找每⼀个i为终点的连续最⼤⼦序列。
所以在递推公式的时候，可以直接选出最⼤的dp[i]。

*******************************************************************************************************/
int maxSubArray(vector<int>& nums) 
{
    int result = INT32_MIN;
    int sum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(sum + nums[i] > nums[i]){
            sum = nums[i] + sum;
        }else{
            sum = nums[i];
        }
        result = max(sum, result);
    }
    return result;
}
int maxSubArray1(vector<int>nums)
{
    if(nums.size() == 0)
        return 0;
    vector<int> dp(nums.size(),0);
    dp[0] = nums[0];
    int maxvlaue = INT32_MIN;
    vector<int> seq;
    for (size_t i = 1; i < nums.size(); i++)
    {
        dp[i] = max(nums[i] , dp[i - 1] + nums[i]); 
    }
    int index = 0;
    for(int i = 0; i < dp.size(); i++)
    {
        if(dp[i] > maxvlaue){
            index = i;
            maxvlaue = dp[i];
        }
    }
    vec_print(dp);
    int tmp = maxvlaue;
    vector<vector<int>> result;
    for(int i = index;i > 0 ; i--)
    {
        seq.push_back(nums[i]);
        tmp = tmp - nums[i];
        if(tmp == 0 ) break;  //只能找出其中一组
    }
    reverse(seq.begin(), seq.end());
    vec_print(seq);
    return maxvlaue;
}

int maxSubarray(vector<int>& nums)
{
    if(nums.size() ==0 ) return 0;
    vector<int>dp(nums.size(), 0);
    dp[0] = nums[0];
    int result = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
        if(dp[i] > result) 
            result = dp[i];
    }
    return result;
}
int main()
{
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4};
    vec_print(nums);

    int res  = maxSubarray(nums);
    cout << "res is : " << res << endl;
    cout << "hello " << endl;
    return 0;
}