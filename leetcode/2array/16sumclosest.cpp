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
8. Sum Closest
描述
Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may assume that each input would have exactly one
solution.
For example, given array S = {-1 2 1 -4}, and target = 2.
e sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
分析
先排序，然后左右夹逼，复杂度 O(n2)。
**********************************************************************************************************/
vector<vector<int> > threeSumCloest(vector<int>& nums,int target){
    cout << "threeSumCloest : "<< " target = " << target <<endl;
    vector<vector<int>> result;
    if(nums.size() < 3)
        return result;
    sort(nums.begin(),nums.end());
    
    for(int i = 0; i < nums.size() - 2; i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < target)
            {
                j++;
            }
            else if(sum > target)
            {
                k--;
            }
            else
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                result.push_back(temp);
                j++;
                k--;
                while(nums[j] == nums[j-1]  && j < k)
                {
                    j++;
                }
                while(nums[k] == nums[k+1]  && j < k)
                {
                    k--;
                }
            }
        }
    }
    return result;
}

int main()
{  
    vector<int> result;
    vector<vector<int> > douberesult;
 
    // 8. three sum
    vector<int>nums8 = {-1 ,1 ,1, 2 ,2,-4}; 
    vec_print(nums8);
    douberesult = threeSumCloest(nums8,2);
    matrix_print(douberesult);
  
	return 0;
}





















