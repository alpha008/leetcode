#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include "helpvector.h"

class Solution {
public:
    //1. 希尔排序 分而治之 https://www.cnblogs.com/chengxiao/p/6104371.html
    int  shell_sort(vector<int> &nums)
    {
        int n =  nums.size();
        int gap = 0;
        int i = 0,j = 0;
        int key = 0; //n = 10  |  8 9 1 7 2 3 5 4 6 0 
        for(gap = n/2; gap >=1 ; gap /=2)
        { //首先是次数
            for(i = gap;i < n; i++)
            {
                key = nums[i];   //i = 5开始遍历 依次和前面的i - gap比较
                for(j = i - gap;j >=0 && key < nums[j];j = j - gap)
                {
                    nums[j + gap] = nums[j];
                }
                nums[j + gap] = key;   //i = j + gap 
            }
            cout << "gap: " << gap << " | "; vec_print(nums);
        }
				return 0;
    }
};

int main()
{

    return 0;
}