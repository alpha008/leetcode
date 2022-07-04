#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include "helpvector.h"
using namespace std;


class Solution {
public:
    void bubble_sort(vector<int> &nums)
    {
        int n = nums.size();
        for (int  i = 0; i < n - 1; i++) // 冒泡遍历循环遍历n-1次
        { 
            for (int  j = 0; j < n - 1 - i; j++)  // 每循环一次，外循环就可以少循环一次
            {   
                if (nums[j] > nums[j + 1]) // 循环一次，把最大的往后面放置，  // 循环一次最大的在最后面，那么就可以少比较一次
                {
                    swap(nums[j] ,nums[j + 1]);
                }
            }
        }
    }
    void swap(int &a,int &b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
};
int main(){
    Solution ab;
    vector<int> res = {8,9,1,7,2,3,5,4,6,0};
    vec_print(res);
    return 0;
}
