#include <iostream>
#include <vector>
#include "helpvector.h"
using namespace std;

/**************************************************************************
Given a number represented as an array of digits, plus one to the number
末尾数字加1，倒序遍历
***************************************************************************/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(auto it = digits.rbegin(); it != digits.rend(); it++){
            *it = *it + carry; // 先将进位处理
            carry = *it / 10;  // 先求进位
            *it = *it % 10;    // 求余数
        }
        if(carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};

int main()
{
    vector<int> nums = {1,2,2,5,5};
    vec_print(nums);

    int target = 5;
    Solution ab;
    ab.plusOne(nums);
    vec_print(nums);
    cout << "hello" << endl;
    return 0;
}


void plusOne(vector<int>&nums,int target)
{
    int carry = target;
    for(auto it = nums.rbegin();it != nums.rend(); it ++ )
    {
        *it += carry;
        carry = *it /10;
        *it = *it %10;
    }
    if(carry > 0)
        nums.insert(nums.begin(), carry);
}
