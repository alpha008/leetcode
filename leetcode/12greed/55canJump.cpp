#include<iostream>
#include<algorithm>
#include<vector>
#include"helpvector.h"
using namespace std;

/*********************************************************************************************
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
示例 1：
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
示例 2：
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*********************************************************************************************/
// LeetCode, Best Time to Buy and Sell Stock
// 时间复杂度 O(n)，空间复杂度 O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // 只有⼀个元素，就是能达到
        for (int i = 0; i <= cover; i++) { // 注意这⾥是⼩于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
        }
        return false;
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