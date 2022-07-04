
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
373. Partition Array by Odd and Even
题目  分割一个整数数组，使得奇数在前偶数在后。
样例
给定 [1, 2, 3, 4]，返回 [1, 3, 2, 4]。
挑战
在原数组中完成，不使用额外空间。
题解
把一个数组划分为奇数在前偶数在后的状态，要求in place。
很简单，就用双指针法，让两个指针从两头往中间扫描，当左边是偶数右边是奇数时就交换，直到左右指针相遇为止。
***********************************************************************************************/
void partitionArray(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        // 左边是奇数的话就自增，直到找到前面的偶数
        while (nums[left] % 2 == 1) {
            left++;
        }
        // 右边是偶数的话就自减，直到找到后面的奇数
        while (nums[right] % 2 == 0) {
                right--;
        }
        if (left < right && nums[left] % 2 == 0 && nums[right] % 2 == 1) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    partitionArray(nums);
    vec_print(nums);
    return 0;
}
