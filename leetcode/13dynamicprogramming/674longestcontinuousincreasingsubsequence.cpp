#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/***************************************************************************
动规五部曲分析如下：
1. 确定dp数组（dp table）以及下标的含义
dp[i]：以下标i为结尾的数组的连续递增的⼦序列⻓度为dp[i]。
注意这⾥的定义，⼀定是以下标i为结尾，并不是说⼀定以下标0为起始位置。
2. 确定递推公式
如果 nums[i + 1] > nums[i]，那么以 i+1 为结尾的数组的连续递增的⼦序列⻓度 ⼀定等于 以i为结尾的
数组的连续递增的⼦序列⻓度 + 1 。 即： dp[i + 1] = dp[i] + 1;
注意这⾥就体现出和动态规划： 300.最⻓递增⼦序列的区别！
因为本题要求连续递增⼦序列，所以就必要⽐较nums[i + 1]与nums[i]，⽽不⽤去⽐较nums[j]与 nums[i] （j是在0到i之间遍历）。
既然不⽤j了，那么也不⽤两层for循环，本题⼀层for循环就⾏，⽐较nums[i + 1] 和 nums[i]。
这⾥⼤家要好好体会⼀下！
3. dp数组如何初始化
以下标i为结尾的数组的连续递增的⼦序列⻓度最少也应该是1，即就是nums[i]这⼀个元素。所以dp[i]应该初始1;
4. 确定遍历顺序
从递推公式上可以看出， dp[i + 1]依赖dp[i]，所以⼀定是从前向后遍历。
本⽂在确定递推公式的时候也说明了为什么本题只需要⼀层for循环，代码如下：

**************************************************************************/

// 最长连续递增子序列
class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;
        int result = 1;
        vector<int> dp(nums.size() , 1);
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i+1] > nums[i]){
                dp[i+1] = dp[i] + 1;
            }
            if(dp[i+1] > result ) result = dp[i +1];
        }
        return result;
    }
};
// 贪心
int findLengthLCS1(vector<int> &nums)
{
    if(nums.size() == 0)
        return 0;
    int result = 1;
    int count = 1;
    for(int i = 0; i < nums.size() - 1; i++)
    {
        if(nums[i+1] > nums[i]){
           count++; 
        }else{
           count = 1;
        }
        if(count > result) result = count;
    }
    return result;
}
class Solution1 {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int result = 1;
        vector<int> dp(nums.size() ,1);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) { // 连续记录
            dp[i + 1] = dp[i] + 1;
            }
            if (dp[i + 1] > result) result = dp[i + 1];
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {1,3,5,4,7};

    cout << "hello " << endl;
    return 0;
}

