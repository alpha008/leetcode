#include <iostream>
#include <vector>
#include "helpvector.h"
using namespace std;
/*****************************************************************
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note: You may assume that A has enough space to hold additional elements from B. e number of
elements initialized in A and B are m and n respectively.
已经排序，从后面开始合并，位置需要计算
*****************************************************************/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1;
        int index2 = n - 1;

        for (int i = m + n - 1; i >= 0; i--) {
            // 说明都没有越界，直接归并
            if (index1 >= 0 && index2 >= 0) {  // 末尾追加放大元素
                nums1[i] = nums1[index1] > nums2[index2] ? nums1[index1--] : nums2[index2--];
            // 说明 nums1 已经到头了，该把 nums2 中的数据全部复制过来了
            } else if (index2 >= 0) {
                nums1[i] = nums2[index2--];
                // nums2 处理完了啊，nums1 本来就在 1 里，结束
            } else {
                break;
            }
        }
    }
};


int main()
{
    vector<int> numsA = {1,2,3,4};
    vector<int> numsB = {5,7,8,9};

    cout << "hello " << endl;
    return 0;
}