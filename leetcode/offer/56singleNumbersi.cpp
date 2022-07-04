#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(m[nums[i]] == 1){
                res.push_back(nums[i]);
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
    Solution ab;
    ab.singleNumbers(nums);
    cout << "hello " << endl;
    return 0;
}