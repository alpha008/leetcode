#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include"helpvector.h"
using namespace std;
/**********************************************************************************************************
示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
**********************************************************************************************************/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int total = nums1.size() + nums2.size();
        if(total & 0x1)
        {
            return find_kth(nums1, nums2, total / 2 + 1);
        }
        else
        {
            return (find_kth(nums1, nums2, total / 2 ) + find_kth(nums1, nums2, total / 2 + 1) ) /2;
        }
    }
private:
    double find_kth(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<int> temp;
        for(int i = 0; i < nums1.size(); i++)
        {
            temp.push_back(nums1[i]);
        }
        for(int j = 0; j < nums2.size(); j++)
        {
            temp.push_back(nums2[j]);   
        }
        sort(temp.begin(), temp.end());
        return (temp[k -1]);
    }
};

int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution ab;
    int res = ab.findMedianSortedArrays(nums1, nums2);
    cout << "res " << res << endl;
    cout << "hello " << endl;
    return 0;
}