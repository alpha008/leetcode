/**************************************************************************
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2n2).
There is only one duplicate number in the array, but it could be repeated more than once.
***************************************************************************/
#include <iostream>
#include <vector>
#include "helpvector.h"
#include <set>
using namespace std;
/*************************************************************************************************************
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。
你设计的解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。
示例 1：

输入：nums = [1,3,4,2,2]
输出：2
示例 2：

输入：nums = [3,1,3,4,2]
输出：3
示例 3：

输入：nums = [1,1]
输出：1
示例 4：

输入：nums = [1,1,2]
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-duplicate-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

下面解法是找到所有的消失的不对应的数字
***************************************************************************************************************/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int  result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i + 1) // 将nums[i]的元素换到    nums[nums[i] - 1]
            {                       // 比如 5换到下标为4的位置上    当换不动了，说明有重复
                if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                {
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);  // 将其与该放的那个位置交换(nums[i] - 1)
            }
        }
        for(int i = 0;i < nums.size(); i++){
            if(nums[i] != (i + 1))
                result = nums[i];    
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {1,2,3,4,4};
    vec_print(nums);
    Solution ab;

    cout << ab.findDuplicate(nums) << endl;
    vec_print(nums);
    cout << "hello" << endl;
    return 0;
}
