#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*****************************************************************
示例 1：
输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
示例 2：
输入：nums = [-1,0]
输出：[-1,0]
示例 3：
输入：nums = [0,1]
输出：[1,0]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
******************************************************************/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i = 0; i< nums.size();i++){
            m[nums[i]]++;
        }    
        for(int i = 0; i < nums.size();i++){
            if(m[nums[i]] == 1){
                res.push_back(nums[i]);
            }
        }    
        return res;
    }
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;  // 找到最右边为1的位置，对数组进行分割
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
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