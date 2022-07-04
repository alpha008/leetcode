#include <iostream>
#include <vector>
#include "helpvector.h"
using namespace std;
/**********************************************************************************************************
27. 删除数组中为target的元素
Given an array and a value, remove all instances of that value in place and return the new length.
order of elements can be changed. It doesn’t matter what you leave beyond the new length
删除元素后需要调整数组大小，或者允许后面的值不动，在打印时，打印前index个
**********************************************************************************************************/
class Solution{
public:
    int removeElement(vector<int> &nums,int elem)
    {
        int index = 0;
        for(int i = 0 ;i < nums.size();i++)
        {
            if(nums[i] != elem)
            {
                nums[index++] = nums[i];
            }
        }
        nums.resize(index);
        return index;
    }
};
int main()
{
    vector<int> nums = {4,5,6,7,0,1,2,2};
    vec_print(nums);
    int target = 1;
    Solution ab;
    cout << "size :" << ab.removeElement(nums, target) << endl;
    vec_print(nums);
    cout << "hello" << endl;
    return 0;
}

