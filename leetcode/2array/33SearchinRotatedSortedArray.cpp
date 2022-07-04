#include <iostream>
#include <vector>
#include "helpvector.h"
using namespace std;
/*********************************************************************************************
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array
**********************************************************************************************/
int searchFromRoateArray(vector<int> &nums,int target)
{
    int fisrt = 0;
    int last = nums.size() - 1;
    while(fisrt !=last)
    {
        const int mid = (fisrt + last) /2;
        if(nums[mid] == target)
            return mid;
        if(nums[fisrt] <= nums[mid]) //如果递增 左边区间
        {
            if(nums[fisrt] <= target && target < nums[mid])
            {
                last = mid; //如果递增 左边区间 且在左边区间
            }
            else
            {
                fisrt = mid +1;
            }
        }
        else   //如果递减 右边区间递增
        {
            if(nums[mid] < target && target <= nums[last])
            {
                fisrt = mid + 1; //如果递减 右边区间递增 且在右边区间
            }   
            else
            {
                last = mid;
            } 
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    vec_print(nums);
    int target = 1;
    cout << searchFromRoateArray(nums, target) <<endl;
    vec_print(nums);
    cout << "hello" << endl;
    return 0;
}

