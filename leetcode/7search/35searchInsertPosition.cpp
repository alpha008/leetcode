#include<iostream>
#include<vector>
#include<algorithm>
#include"helpvector.h"
using namespace std;
/***********************************************************************************************
35 Given a sorted array and a target value, return the index if the target is found. If not, return the index
where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
************************************************************************************************/
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while(l + 1 != r)
        {
            int mid = l + (r - l ) /2;
            if(nums[mid] < target){
                l = mid;
            }else{
                r = mid;
            }
        }
        return r;
    }
};
class Solution {
public:
    int searchInsert(vector<int> nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound (ForwardIterator first,
    ForwardIterator last, T value) {
    while (first != last) {
        auto mid = next(first, distance(first, last) / 2);
        if (value > *mid) first = ++mid;
        else last = mid;
    }
        return first;
    }
};

int main()
{
    vector<int > nums = {1,3,5,6};
    vec_print(nums);
    Solution ab;
    int target = 8;
    int res  = ab.searchInsert(nums, target);
    cout << "target " << target <<  "  insert posstion is " << res << endl;
    cout << " hello " << endl;

}

