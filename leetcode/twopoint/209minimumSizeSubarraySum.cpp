#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<limits.h>
#include<string>
#include<unordered_map>
#include"helpvector.h"
using namespace std;
/***********************************************************************************************
这道题给定了我们一个数字，让我们求子数组之和大于等于给定值的最小长度。
我们需要定义两个指针left和right，分别记录子数组的左右的边界位置，然后我们让right向右移，直到子数组和大于等于给定值或者right达到数组末尾。

然后我们更新最短距离，并且将left像右移一位，然后把left左边的那个元素从sum中减去。
然后重复上面的步骤，直到right到达末尾。没有排序的子数组

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
***********************************************************************************************/
int minimumSize(vector<int> nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }
    int left = 0, right = 0;
    int minLength = INT_MAX;
    int sum = 0;

    for (left = 0; left < nums.size(); left++) {
        while (right < nums.size() && sum < target) {
            sum += nums[right];
            right++;
        }
        if (sum >= target) {// 更新最小长度，如果没找到那么 minLength = INT_MAX
            minLength = min(minLength, right - left);
        }
        sum -= nums[left];// 缩小左边界
    }
    
    return (minLength != INT_MAX) ? minLength : -1;
}

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    vec_print(nums);
    int target = 7;
    int res = minimumSize(nums,target);
    cout << "res is " << res << endl;
    return 0;
}