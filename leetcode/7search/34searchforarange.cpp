#include<iostream>
#include<vector>
#include<algorithm>
#include"helpvector.h"
using namespace std;
/***********************************************************************************************
34. Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4]
************************************************************************************************/
vector<int> searchRange(const vector<int > &nums, int target) 
{
    const int l = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    const int u = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
    if (nums[l] != target) // not found
        return vector<int> { -1, -1 };
    else
        return vector<int> { l, u };
}

int main()
{
    vector<int > nums = {5, 7, 7, 8, 8, 10};
    vec_print(nums);
    vector<int> res;
    res  = searchRange(nums, 8);
    vec_print(res);
    cout << " hello " << endl;

}

