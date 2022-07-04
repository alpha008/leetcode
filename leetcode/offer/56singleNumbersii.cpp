#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
示例 1：
输入：nums = [3,4,3,3]
输出：4
示例 2：
输入：nums = [9,1,7,9,7,9,7]
输出：1
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k = 3;
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            int count = 0;  // 计算32个bit上1是否出现
            for(int j = 0; j < nums.size(); j++){
                count += (nums[j] >> i) & 1;
            }
            if(count % k != 0){
                res |= (1 <<i);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {3,4,3,3};
    int target =  9;
    vector<int> res;
    Solution ab;
    ab.singleNumber(nums);
    cout << "hello " << endl;
    return 0;
}