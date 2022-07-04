#include<iostream>
#include<vector>
#include"helpvector.h"
using namespace std;
/**********************************************************************************************************
示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**********************************************************************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while( l +1 != r)
        {
            int mid = l + (r - l ) / 2;
            if(nums[mid] < target){
                l = mid;
            }else{
                r = mid;
            }
        }
        if(nums[r] == target)
            return r;
        return -1;
    }
};

int main()
{
    vector<int>  nums = {-1,0,3,5,9,12};

    int target = 3;
    Solution ab;
    ab.search(nums,16);

    cout << " hello " << endl;

}

