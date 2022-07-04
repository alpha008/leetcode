#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/**********************************************************************************************************
1. Two Sum
假设解唯一，并且元素没有重复
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. 使用哈希表进行缓存，降低时间复杂度
**********************************************************************************************************/
class Solution{
public:
    vector<int> findtwoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> indices;  //哈希表无序
        for (int index = 0; index < nums.size(); index++) 
        {
            if (indices.find(target - nums[index]) != indices.end())  // 说明找到了
            {
                return { indices[target - nums[index]], index };
            }
            indices[nums[index]] = index;// value + index  根据值找下标
        }
        return {}; // 最后没找到返回空
    }
    vector<int> findx(vector<int> nums, int target)
    {
        unordered_map<int ,int > valueIndex;
        for(int index = 0; index < nums.size(); index ++)
        {
            if(valueIndex.find(target - nums[index]) != valueIndex.end())
            {
                return {valueIndex[target - nums[index]], index};
            }
            else
                valueIndex[nums[index]] = index;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;
    Solution ab;
    res = ab.findx(nums, target);
    for (int i = 0 ; i < res.size(); i++)
    { 
        cout << res[i] << " " ;
    }
    cout << endl;
    cout << "hello " << endl;
    return 0;
}



