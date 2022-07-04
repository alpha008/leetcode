#include<iostream>
#include<algorithm>
#include<vector>
#include"helpvector.h"
using namespace std;

/*********************************************************************************************
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。
示例 1:
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
示例 2:
输入: nums = [2,3,0,1,4]
输出: 2
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*********************************************************************************************/
// LeetCode, Best Time to Buy and Sell Stock
// 时间复杂度 O(n)，空间复杂度 O(1)
// 版本⼀
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0; // 当前覆盖最远距离下标
        int ans = 0; // 记录⾛的最⼤步数
        int nextDistance = 0; // 下⼀步覆盖最远距离下标
        for (int i = 0; i < nums.size(); i++) 
        {
            nextDistance = max(nums[i] + i, nextDistance); // 更新下⼀步覆盖最远距离下标
            if (i == curDistance) 
            { // 遇到当前覆盖最远距离下标
                if (curDistance != nums.size() - 1) 
                { // 如果当前覆盖最远距离下标不是终点
                    ans++; // 需要⾛下⼀步
                    curDistance = nextDistance; // 更新当前覆盖最远距离下标（相当于加油了）
                    if (nextDistance >= nums.size() - 1) break; // 下⼀步的覆盖范围已经可以达到终点，结束循环
                } else{
                    break; // 当前覆盖最远距离下标是集合终点，不⽤做ans++操作了，直接结束
                } 
            }
        }
        return ans;
    }
};
// 版本⼆
class Solution1 {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0; // 当前覆盖的最远距离下标
        int ans = 0; // 记录⾛的最⼤步数
        int nextDistance = 0; // 下⼀步覆盖的最远距离下标
        for (int i = 0; i < nums.size() - 1; i++) 
        { // 注意这⾥是⼩于nums.size() - 1，这是关键所在
            nextDistance = max(nums[i] + i, nextDistance); // 更新下⼀步覆盖的最远距离下标
            if (i == curDistance) 
            { // 遇到当前覆盖的最远距离下标
                curDistance = nextDistance; // 更新当前覆盖的最远距离下标
                ans++;
            }
        }
        return ans;
    }
};
int main()
{   
    vector<int> pricces = {7,1,5,3,6,4};
    vec_print(pricces);
    Solution ab;

    cout << "hello " << endl;
    return 0;
}