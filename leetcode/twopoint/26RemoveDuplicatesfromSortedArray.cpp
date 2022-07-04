#include <iostream>
#include <vector>
#include "helpvector.h"
using namespace std;
/**********************************************************************************************************
11. 删除数组中重复的数字  --- 数组是有序的
**********************************************************************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int slow = 0;
        for(int fast = 1; fast < nums.size() ; fast++)
        {
            if(nums[slow] != nums[fast]){
                nums[++slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
/*********************************************************************************************
Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]
**********************************************************************************************/
int removeDumplicates(vector<int> &nums)
{
    int cur = 0;
    int occur = 0;
    for(int index = 1; index < nums.size(); index++)
    {
        if(nums[cur] == nums[index])
        {
            if(occur < 2)
            {
                nums[++cur] = nums[index];
                occur++;
            }
        }
        else
        {
            nums[++cur] = nums[index];
            occur = 1 ;   
        }
    }
    nums.resize(cur);
    return cur+1;
}
int main()
{
    vector<int> nums = {1,1,2};

    Solution ab;
    ab.removeDuplicates(nums);

    vec_print(nums);
    
    cout << "hello" << endl;
    return 0;
}

