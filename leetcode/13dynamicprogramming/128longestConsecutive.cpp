#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

/******************************************************************************
示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*********************************************************************************/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        int res = 0;
        for(auto ele : nums){
            hash_set.insert(ele);
        }
        for(auto x: hash_set){
            if (!hash_set.count(x-1))
            {
                int y = x;
                while (hash_set.count(y + 1)){ y++;}
                res = max(res,y - x +1 );
            }
        }
        return res;
    }
};



int main()
{
    vector<int> nums = {7,1,5,3,6,4};
    Solution ab;
    ab.longestConsecutive(nums);
    cout << "hello " << endl;
    return 0;
}