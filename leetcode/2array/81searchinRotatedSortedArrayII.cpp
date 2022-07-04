#include <iostream>
#include <vector>
#include "helpvector.h"
using namespace std;

/*********************************************************************************************
Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
分析
允许重复元素，则上一题中如果 A[m]>=A[l], 那么 [l,m] 为递增序列的假设就不能成立了，比
如 [1,3,1,1,1]。
如果 A[m]>=A[l] 不能确定递增，那就把它拆分成两个条件：
• 若 A[m]>A[l]，则区间 [l,m] 一定递增
• 若 A[m]==A[l] 确定不了，那就 l++，往下看一步即可。

**********************************************************************************************/
int searchFromRoateArrayII(vector<int> &nums,int target)
{

    
   return 0;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    vec_print(nums);
    int target = 1;
    cout << searchFromRoateArrayII(nums, target) <<endl;
    vec_print(nums);
    cout << "hello" << endl;
    return 0;
}

