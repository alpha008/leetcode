#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
统计一个数字在排序数组中出现的次数。
示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target){
                res++;
            }
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