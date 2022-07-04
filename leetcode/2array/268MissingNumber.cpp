#include<iostream>
#include<vector>
#include"helpvector.h"
using namespace std;

/****************************************************************************************
题目描述:
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
示例:  暗含 每个数字仅出现一次
示例 1:
输入: [3,0,1]  0 1 2 3
输出: 2
示例 2:
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
*****************************************************************************************/
int findMissingNum(vector<int> nums)
{
    int missing = 0;
    for(int i = 0; i < nums.size(); i ++)
    {
        missing = missing ^ nums[i] ^ i  ;
    }
    return missing ^ nums.size();
}

int main()
{
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    vec_print(nums);
    int res = findMissingNum(nums);
    cout << "res is " << res  << endl;
    cout << "hello " << endl;
    return 0;
}