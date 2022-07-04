#include<unordered_set>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/***********************************************************************
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。
示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***********************************************************************/
class Solution1 {
public:                                 // 维护一个队列，队首存储窗口内最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;                   // 双端队列
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();           // 每次加入都要和队列中的值比较，队首存最大值
            }
            q.push_back(i);             // 队首存储当前窗口内的最大值，剩下的位置挨个存入
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {  
                // 下面将队列中不在窗口内的元素剔除后，那么这里在判断时，始终能够存储窗口内最大
                q.pop_back();  // 和队列中所有元素相比 加入最大的，将之前的弹出
            } 
            q.push_back(i);    // 如果不大于之前的，那么直接加入队列
            while (q.front() <= i - k) {  // 将不在窗口内的元素剔除
                q.pop_front(); 
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for(int i = 0;  i < k; i++){
            q.emplace(nums[i], i);
        }
        vector<int> ans {q.top().first};
        for(int i = k ; i < n ; i++){
            q.emplace(nums[i],i);
            while (q.top().second < i - k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,5,6};
    Solution ab;
    vector<int> res = ab.maxSlidingWindow( nums , 3);
    return 0;
}
