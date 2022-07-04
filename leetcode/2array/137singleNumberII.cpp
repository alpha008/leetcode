#include <iostream>
#include <vector>
#include "helpvector.h"
using namespace std;
/**********************************************************************************************************
137. single element,appearce k  others

Given an array of integers, every element appears three times except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using
extra memory

本题和上一题 Single Number，考察的是位运算。
方法 1：创建一个长度为 sizeof(int) 的数组 count[sizeof(int)]， count[i] 表示所有元
素的 1 在 i 位出现的次数。如果 count[i] 是 3 的整数倍，则忽略；否则就把该位取出来组成答案。
方法 2：用 ones 记录到当前处理的元素为止，二进制 1 出现“1 次”（mod 3 之后的 1）的有哪
些二进制位；用 twos 记录到当前计算的变量为止，二进制 1 出现“2 次”（mod 3 之后的 2）的有哪
些二进制位。当 ones 和 twos 中的某一位同时为 1 时表示该二进制位上 1 出现了 3 次，此时需要
清零。即用二进制模拟三进制运算。最终 ones 记录的是最终结果。
1:   0000 0000 0000 0000 0000 0000 0000 0001
1:   0000 0000 0000 0000 0000 0000 0000 0001
1:   0000 0000 0000 0000 0000 0000 0000 0001

2:   0000 0000 0000 0000 0000 0000 0000 0010
2:   0000 0000 0000 0000 0000 0000 0000 0010
2:   0000 0000 0000 0000 0000 0000 0000 0010

3:   0000 0000 0000 0000 0000 0000 0000 0011

**********************************************************************************************************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k = 3;
        vector<int> count(sizeof(int)*8, 0);

        for(int i = 0 ;i < nums.size(); i++)
        {
            for(int j = 0;j < count.size(); j++)
            {
                count[j] += (nums[i] >> j) & 0x1;
                count[j] %= k; //假如出现k次，那么这个bit位将会变成0
            }
        }
        int result = 0;
        for(int i = 0;i < count.size();i++)
        {
            result += (count[i] << i);
        }
        return result;
    }
};
class Solution1 {
public:
    int singleNumber(vector<int> &nums)
    {
        int k = 3;
        const int W = sizeof(int) * 8;
        int count[W];
        fill_n(&count[0], W, 0); // 将该数组所有bit位置填充为0
        for(int i = 0 ;i < nums.size(); i++)
        {
            for(int j = 0;j < W; j++)
            {
                count[j] += (nums[i] >> j) & 0x1;
                count[j] %= k; //假如出现k次，那么这个bit位将会变成0
            }
        }
        int result = 0;
        for(int i = 0;i < W;i++)
        {
            result += (count[i] << i);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1,1,1,2,2,2,3,3,3,4};
    vec_print(nums);
    int target = 1;
    Solution ab;
    cout << "single numbers is " << ab.singleNumber(nums) <<endl;
 
    cout << "hello" << endl;
    return 0;
}

