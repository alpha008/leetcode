
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
539. Move Zeroes
把一个数组的所有0移动到末尾，且不改变原数组非零元素之间的相对位置。要求in place进行。
第一种方法是双指针移动法，left和right指针一开始都置为起始元素，然后让right去遍历寻找非0元素。找到了非0元素后，
就把两个指针的元素互换，使得后面的right指向的非0元素可以把left指向的0给替换掉。
交换完后，此时的left应该指向下一个0元素，所以left要自增。同时外层循环让right自增，继续去寻找下一个非0元素：
Given an array nums, write a function to move all 0’s to the end of it while maintaining the relative order 
of the non-zero elements.

Example
Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
***********************************************************************************************/
void moveZeroes(vector<int> &nums) {
    int left = 0, right = 0;
    while (right < nums.size()) {  // right从有边界开始找，找到往左边界填充
        // right指针找到一个非0的数，就与left指针交换
        if (nums[right] != 0) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            // 交换后，left自增
            left++;
        }
        right++;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    vec_print(nums);
    return 0;
}
