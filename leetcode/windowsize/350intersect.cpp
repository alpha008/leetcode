#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<deque>
#include "helpvector.h"
using namespace std;

/***********************************************************************
示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
示例 2:

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
************************************************************************/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>  m1;
       vector<int> res;
       for(int i = 0; i < nums1.size(); i++)
       {
           m1[nums1[i]] ++;
       }    
       for(int j = 0 ; j < nums2.size() ;j++)
       {
           if( m1[nums2[j]] > 0 )
           {
               res.push_back(nums2[j]);
               m1[nums2[j]]-- ;
           }
       }
       return res;
    }
};
int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> result;
    Solution ab;
    result =  ab.intersect(nums1,nums2) ;

    vec_print(result);

    return 0;
}


















//239. Sliding Window Maximum -- hard
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(nums.size() == 0)
        return nums;
    vector<int> result;
    deque<int> window;
    for(int i = 0; i < nums.size(); i++)
    {
        while(!window.empty() && nums[i] > nums[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);  //将自己加入队列要排名次

        if(!window.empty() && window.front() <= (i - k))   // 删除上一个窗口的
            window.pop_front();

        if(i >= k - 1)  //主要是为了约束刚开始k个元素组成的窗口
            result.push_back(nums[window.front()]);
    }
    return result;
}