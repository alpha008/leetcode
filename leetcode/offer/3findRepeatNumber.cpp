#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include"helpvector.h"
using namespace std;
/*******************************************************************************************************
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*******************************************************************************************************/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, int> map1;
        for(int i = 0; i< nums.size(); i++){
            if(map1.count(nums[i]) > 0){
                return nums[i];
            }
            map1[nums[i]] = i;
        } 
        return 0;
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