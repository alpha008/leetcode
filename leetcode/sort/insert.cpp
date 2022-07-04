#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include "helpvector.h"
using namespace std;
class Solution {
public:
    //1. 插入排序
    void insert_sort(vector<int>&nums)
    {
        int i ,j ,key ;
        int n = nums.size();
        for ( i = 1; i < n; i++)
        {	
            int key = nums[i];
            for ( j = i; j > 0 &&  key < nums[j-1] ; j--) 
            {                   //挖空的前一个位置和key关键字比较
                nums[j] = nums[j-1]; //往后移动元素
            }
            nums[j] = key;//前面的都比key小，那么j位置就留给key
        }
    }
};
int main(){
    Solution ab;
    vector<int> res = {8,9,1,7,2,3,5,4,6,0};
    vec_print(res);
    ab.insert_sort(res);
    vec_print(res);
    return 0;
}
