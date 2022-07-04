#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include"helpvector.h"
using namespace std;
/*******************************************************************************************************
示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*******************************************************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_set<int> s;
        for(int i = 0; i < nums.size() ;i ++)
        {
            if(s.find(target - nums[i]) != s.end() ){
                res.push_back(nums[i]);
                res.push_back(target - nums[i]); 
                break; 
            }
            s.insert(nums[i]);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}