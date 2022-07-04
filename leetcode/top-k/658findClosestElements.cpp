#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<iostream>
#include<vector>
#include<limits.h>
/***********************************************************************
给定一个排序好的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
整数 a 比整数 b 更接近 x 需要满足：
|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
 
示例 1：
输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]
示例 2：
输入：arr = [1,2,3,4,5], k = 4, x = -1
输出：[1,2,3,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-k-closest-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***********************************************************************/
using namespace std;
// Sliding window
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int minDelta = INT_MAX;

        int delta = 0;
        int startIdx = 0;
        for (int i = 0; i < k; i++) {
            delta += abs(arr[i] - x);
        }

        minDelta = min(delta, minDelta);
        for (int i = k; i < arr.size(); i++) {
           delta -= abs(arr[i - k] - x); 
           delta += abs(arr[i] - x);
           if (delta < minDelta) {
               minDelta = delta;
               startIdx = i - k + 1;
           }
        }

        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + k);
    }
};



int main()
{


    return 0;
}
