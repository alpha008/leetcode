#include<iostream>
#include<vector>
#include<algorithm>
#include"helpvector.h"
using namespace std;
/*****************************************************************************************************************************
示例 1：nums 中的每个值都 独一无二
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：
输入：nums = [1], target = 0
输出：-1
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/leetcode-33-sou-suo-xuan-zhuan-pai-xu-sh-ga4b/
https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/er-fen-sou-suo-zuo-kai-you-kai-qu-jian-b-q7ka/
******************************************************************************************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1)  return target == nums[0] ? 0 : -1;
        int left = -1, right = nums.size();
        while (left + 1 != right)
        {
            int mid = left + (right - left)/2;
            if (target >= nums[0])    // target在左递增段
            {
                if (nums[0] <= nums[mid] && nums[mid] <= target)   //isBlue.1
                    left = mid;
                else
                    right = mid;
            }
            else         // target在右的递增段
            {
                if (nums[0] <= nums[mid] || nums[mid] <= target)   //isBlue.2
                    left = mid;
                else
                    right = mid;
            }
        }
        return left == -1 || nums[left] != target ? -1 : left;
    }
};

class Solution1 {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            /*if (nums[l] == nums[mid] && nums[mid] == nums[r]) {// 当出现左右边界等于目标值时，不能确定搜索区间，两边同时缩小
                ++l;
                --r;
            } else*/ if (nums[l] <= nums[mid]) { // l < m 说明 l-m为递增区间
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }                   
            } else {  // nums[l] > nums[mid]  说明mid到末尾为递增区间    【mid - n-1】 为递增区间
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }    // 遵循左闭右开原则
            }
        }
        if(l < n && nums[l] == target) return l ;
        else return -1;
    }
};
int main()
{
    vector<int > nums = {4,5,6,7,0,1,2};
    vec_print(nums);
    int res;
    Solution ab;
    res  = ab.search(nums, 8);

    cout << " res " << res <<  endl;

}

