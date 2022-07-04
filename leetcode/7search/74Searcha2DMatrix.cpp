#include<iostream>
#include<vector>
#include"helpvector.h"
using namespace std;
/**********************************************************************************************************
74. Search a 2D Matrix
For example, Consider the following matrix:7.3 Search a 2D Matrix 117
[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
Given target = 3, return true.
把一个长度为n的一维数组转化为 m*n 的二维数组 (m*n = n)后，那么原一维数组中下标为i的元素将出现在二维数组中的 [i/n][i%n]
画图看一下就好看多了，第i个，分配给，下面是按照列来分组的，[] [] [] [] [] [] [] [] 所以除以列
**********************************************************************************************************/
bool searchMatrix(const vector<vector<int>>& matrix ,int target){
    const size_t m = matrix.size();
    const size_t n = matrix.front().size();
    int first = 0;
    int last = m * n;
    while(first < last){
        int mid = first + (last - first )/2;
        int value = matrix[mid /n ][mid %n];  // 第mid个元素的下标
        if(value == target)
            return true;
        else if(value < target)
            first = mid + 1;
        else
            last = mid; // 左闭 右开
    }
    return false;
}

int main()
{
    vector<vector<int>> nums = {
        {1, 3, 5, 7},{10, 11, 16, 20},{23, 30, 34, 50}
    };
    matrix_print(nums);
    int target = 3;
    bool is = searchMatrix(nums,target);
    cout << "target " << target << " " << is <<endl;
    cout << " hello " << endl;

}

