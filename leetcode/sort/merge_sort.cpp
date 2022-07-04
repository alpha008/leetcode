#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include "helpvector.h"
using namespace std;
class Solution {
public:
    // 归并排序 + 外部存储  https://www.cnblogs.com/chengxiao/p/6194356.html
    vector<int> merge_sort(vector<int>& nums) {
        vector<int>temp(nums.size(), 0);
        merge_sort(nums, temp, 0, nums.size()-1);
        return nums;
    }
    void merge_sort(vector<int>&nums, vector<int>& temp, int start, int end){
        if(start >= end)
            return ;
        int middle = start + (end - start ) /2;
        merge_sort(nums, temp, start ,middle);
        merge_sort(nums, temp , middle+1, end);
        merge(nums, temp, start, middle, end);
    }
    void merge(vector<int>&nums, vector<int>& temp, int start, int middle, int end){
        int i = start , j = middle + 1, k = start;
        while(i <= middle && j <= end){
            if(nums[i] > nums[j]){
                temp[k++] = nums[j++];
            }else{
                temp[k++] = nums[i++];
            }
        }
        while(i <= middle ){
            temp[k++] = nums[i++];
        }
        while(j <= end){
            temp[k++] = nums[j++];
        }
        // 需要将计算的中间结果保存到原数组中
        for(i = start; i <= end; i++){
            nums[i] = temp[i];
        }
    }
};
int main(){
    Solution ab;
    vector<int> res = {8,9,1,7,2,3,5,4,6,0};
    vec_print(res);
    return 0;
}
