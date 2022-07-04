#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include"helpvector.h"
using namespace std;
/**********************************************************************************************************
41. 乱序数组，找到第一个消失的正数
Given an unsorted integer array, find the first missing positive integer.
For example, Given [1,2,0]      return 3
                   [3,4,-1,1]   return 2
本质上是桶排序 (bucket sort)，每当 A[i]!= i+1 的时候，将 A[i] 与 A[A[i]-1] 交换，直到无法
交换为止，终止条件是 A[i]== A[A[i]-1]。
**********************************************************************************************************/
// 当所有的元素都遍历完成时，能保证在数组大小范围内的元素都已经放在了该放的位置上

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size() ; i++){
            while(nums[i]!= i+1){
                if(nums[i] <=0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]){
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size() + 1;
    }
};


int main()
{  
    vector<int> result;
    vector<vector<int> > douberesult;
    // 41. 乱序数组，找到第一个消失的正数
    vector<int>nums10 = {1,2,0,10,3,5}; 
    vec_print(nums10);
    Solution ab;
    cout << "first missing positive is "<<ab.firstMissingPositive(nums10) << endl;
	return 0;
}