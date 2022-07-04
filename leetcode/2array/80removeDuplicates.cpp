#include <iostream>
#include <vector>
#include "helpvector.h"
using namespace std;
/**********************************************************************************************************
示例 1：

输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 不需要考虑数组中超出新长度后面的元素。
示例 2：

输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。 不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**********************************************************************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int occur = 1;
        int index = 0;
        for(int i = 1; i < nums.size();i++){
            if(nums[index] != nums[i]){
                nums[++index] =  nums[i];
                occur = 1;
            }else{
                if(occur < 2){
                    nums[++index] = nums[i];
                    occur++;
                }
            }
        } 
        return index+1;
    }
};

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2,2};
    vec_print(nums);
    int target = 1;
    Solution ab;
    cout << "size :" << ab.removeDuplicates(nums) <<endl;
    vec_print(nums);
    cout << "hello" << endl;
    return 0;
}

