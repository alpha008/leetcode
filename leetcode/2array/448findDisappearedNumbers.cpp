
#include<iostream>
#include<vector>
#include<string>
#include"helpvector.h"
using namespace std;
/*********************************************************************
​要找一个n长度的数组里面缺了1-n里的哪些数字，数组里面的数字会重复。
​查缺，也可以直接哈希
示例 1：
输入：nums = [4,3,2,7,8,2,3,1]
输出：[5,6]
示例 2：
输入：nums = [1,1]
输出：[2]
**********************************************************************/
void bucket_sort_test(vector<int>&nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        while(nums[i] != i + 1)
        {
            if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                break;
            swap(nums[i], nums[nums[i] - 1]);  // 将其与该放的那个位置交换(nums[i] - 1)
        }
    }
}
void bucket_sort(vector<int>&nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        while(nums[i] != i + 1) // 将nums[i]的元素换到    nums[nums[i] - 1]
        {                       // 比如 5换到下标为4的位置上    当换不动了，说明有重复
            if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
            {
                cout << "i " << i << "  aa:  "<< nums[i] << "  bb: " <<  nums[nums[i] - 1] << endl;
                break;
            }
            swap(nums[i], nums[nums[i] - 1]);  // 将其与该放的那个位置交换(nums[i] - 1)
        }
        cout << "swap no: " << i << endl;
        vec_print(nums);
    }
}

vector<int> firstMissingPositive(vector<int>&nums){
    vector<int> result;
    bucket_sort(nums);
    for(int i = 0;i < nums.size(); i++){
        if(nums[i] != (i + 1))
            result.push_back(i + 1) ;     
    }
    return result;
}

int main()
{
    //vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> nums = {4,4,2,2,5};
    vec_print(nums);
    vector<int> res = firstMissingPositive(nums);
    vec_print(res);
    return 0; 
}