#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "helpvector.h"
using namespace std;
class Solution {
public:
    // 快速排序 https://www.sohu.com/a/246785807_684445/
    // 快速排序在每一轮挑选一个基准元素，并让其他比它大的元素移动到数列一边，比它小的元素移动到数列的另一边，从而把数列拆解成了两个部分。
    vector<int> quick_sort(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        quick(nums, start , end);
        return nums;
    }
    void quick(vector<int>&nums, int start , int end){
        if(start >= end)
            return ;   //递归结束条件
        int i = start;
        int j = end;
        int key = nums[start]; // 哨兵
        while(i < j){  // 10 3 5 4 8 8 4 57 2 
            while(i < j && key <= nums[j]) // 从右边开始找第一个比key小的元素
            {
                j--; 
            }
            nums[i] = nums[j];  //后面挖空 ，向前填充
            while(i < j && key >= nums[i])// 从左边找第一个比key大的元素
            {
                i++;
            }
            nums[j] = nums[i];  // 前面挖空向后面填充
        }  // 每个循环结束  left  < key < right
        nums[j] = key;     //nums[i] = key
        vec_print(nums);
        quick(nums, start , i - 1);
        quick(nums, i + 1,  end );    
    }
};
int main(){
    Solution ab;
    vector<int> res = {8,9,1,7,2,3,5,4,6,0};
    vec_print(res);
    ab.quick_sort(res);
    vec_print(res);
    return 0;
}


