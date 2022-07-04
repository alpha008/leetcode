#include<iostream>
#include<vector>
#include<algorithm>
#include"helpvector.h"
using namespace std;

/************************************************************************************
 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
1. dp[i]的定义
dp[i]表示i之前包括i的最⻓上升⼦序列。
2. 状态转移⽅程
位置i的最⻓升序⼦序列等于j从0到i-1各个位置的最⻓升序⼦序列 + 1 的最⼤值。
所以： if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
注意这⾥不是要dp[i] 与 dp[j] + 1进⾏⽐较，⽽是我们要取dp[j] + 1的最⼤值。
3. dp[i]的初始化
每⼀个i，对应的dp[i]（即最⻓上升⼦序列）起始⼤⼩⾄少都是是1.
4. 确定遍历顺序
dp[i] 是有0到i-1各个位置的最⻓升序⼦序列 推导⽽来，那么遍历i⼀定是从前向后遍历。
j其实就是0到i-1，遍历i的循环⾥外层，遍历j则在内层，代码如下：
*************************************************************************************/ 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


// 初始化状态容器
// 遍历顺序
// 转移方程
// 处理结果
vector<vector<int>> longestIncreasingResult(vector<int> nums)
{
    vector<vector<int>> result;
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> temp;
    for(int i = 1; i < n;i++)
    {
        temp.clear();
        for(int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                temp.push_back(nums[j]);
            }
            temp.push_back(nums[i]);
        }
        result.push_back(temp);
    }
    return result;
}
int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    vec_print(nums);
    vector<vector<int>>res = longestIncreasingResult(nums);
    matrix_print(res);
    cout << "hello " << endl;
    return 0;
}