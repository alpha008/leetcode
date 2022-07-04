#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include "helpvector.h"
using namespace std;
//由于在直接选择排序中存在着不相邻元素之间的互换，因此，直接选择排序是一种不稳定的排序方法。
class Solution {
public:
    //1.  选择排序 选哨兵 
    void select_sort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i< n-1; i++)
        {
            int k = i;                     // k can be viewed as the index of min value
            for (int j = i + 1;j < n; j++)
            {                              // find the min value
                if (nums[j] < nums[k])
                {
                    k = j;
                }
            }
            swap(nums[i], nums[k]);        // store the min value to the start
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
