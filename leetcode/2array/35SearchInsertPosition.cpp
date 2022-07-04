#include<iostream>
#include<algorithm>
#include<vector>
#include"helpvector.h"
using namespace std;


/**********************************************************************************************************
35 .Search Insert Position
描述 按顺序排好的数组，找到插入的位置
Here are few examples.
    [1,3,5,6], 5 → 2
即 std::lower_bound()
**********************************************************************************************************/
int searchInsert(vector<int>nums,int target){
    int index = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    cout <<"searchInsert: insert " << target <<" is  "<< index <<  endl; 
    return index;
}

int main()
{
  // 9. Search Insert Position
    vector<int>nums9 = { 1,3,5,6 }; 
    vec_print(nums9);
    searchInsert(nums9, 5);
    cout << "hello " << endl;
    return 0;
}