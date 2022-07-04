#include <iostream>
#include <vector>
#include "helpvector.h"
using namespace std;
//遍历一维数组
/*********************************************************************************************
Given an array of integers, every element appears twice except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using
extra memory
 {1,1,2,2,3,3,4}
**********************************************************************************************/
class Solution{
public:
    int singleNumber(vector<int> &nums)
    {
        int singleNumber = nums[0];
        for(int i = 1 ; i < nums.size(); i ++)
        {
            singleNumber ^= nums[i];
        }
        return singleNumber;
    }

};


int main()
{
    vector<int> nums = {1,1,2,2,3,3,4};
    vec_print(nums);
    int target = 1;
    Solution ab;
    cout << "single numbers is " << ab.singleNumber(nums) <<endl;
 
    cout << "hello" << endl;
    return 0;
}

