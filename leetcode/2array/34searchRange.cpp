#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include"helpvector.h"
using namespace std;

/**********************************************************************************************************
7. 在数组中查找target的下标的区间
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
**********************************************************************************************************/
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        cout << "searchRange: "<< "target "<<target << endl;
        //distance 计算两个迭代器之间的距离
        //lower_bound(起始地址，结束地址，要查找的数值) 返回的是数值 第一个出现的位置。
        //upper_bound(起始地址，结束地址，要查找的数值) 返回的是 第一个大于待查找数值 出现的位置。
        const int l = distance(nums.begin(), lower_bound(nums.begin(),nums.end() ,target));
        const int u = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
        if (nums[l] != target) // 说明没找到
            return vector<int>{-1, -1};//匿名对象
        else
            return vector<int>{l, u };
    }
};
/*

作者：sui-xin-yuan
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/lan-hong-hua-fen-fa-dan-mo-ban-miao-sha-e7r40/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/lan-hong-hua-fen-fa-dan-mo-ban-miao-sha-e7r40/

*/
class Solution {
public:
    int binarySearchLeft(vector<int>& nums, int target) {
        int l = -1, r =  nums.size();
        while (l + 1 != r) {
            int mid = l + (r-l)/2;
            if(nums[mid] < target) { // 将 < target 的元素归入左边界
                l = mid;  // 蓝色区域
            } else {
                r = mid;
            }
        }
        return r; // r为第一个 >= target的下标
    }
    int binarySearchRight(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 != r) {
            int mid = l + (r-l)/2;
            if(nums[mid] <= target) { // 将 <= target 的元素归入左边界
                l = mid;  // 蓝色区域
            } else {
                r = mid;
            }
        }
        return l;// l为最后一个 <= target的下标
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx  = binarySearchLeft(nums, target);
        int rightIdx = binarySearchRight(nums, target);
        if(leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return {leftIdx, rightIdx};
        }
        return {-1, -1};
    }
};

int main()
{  
    vector<int> result;
    // 7. 在数组中查找target的下标的区间
    vector<int>range = { 5, 7, 7, 8, 8, 10 }; 
    vec_print(range);
    Solution ab;
    result = ab.searchRange(range,8);
    vec_print(result);
  
	return 0;
}