
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<limits.h>
#include<string>
#include<unordered_map>
#include"helpvector.h"
using namespace std;
/***********************************************************************************************
387. The Smallest Difference
给定两个数组，要求在这两个数组里找到两个数的差，使得两数之差最小。最直观的方法是两层循环逐个去遍历，时间复杂度是O(N*N)。
但是我们可以通过排序+双指针把时间复杂度降到O(N*logN)。先把两个数组排好序。然后同时从两个数组的起始位置往后扫描记录最小差。
哪个数字小，就先移动那个数组的遍历指针，以减少两数之差的距离。O(m+n)

题目
给定两个整数数组（第一个是数组 A，第二个是数组 B），在数组 A 中取 A[i]，数组 B 中取 B[j]，A[i] 和 B[j]两者的差越小越好(|A[i] - B[j]|)。
返回最小差。
样例
给定数组 A = [3,4,6,7]， B = [2,3,8,9]，返回 0。
***********************************************************************************************/
int smallestDifference(vector<int> &numsA, vector<int> &numsB) {
    if (numsA.size() == 0 || numsB.size() == 0) {
        return 0;
    }
    sort(numsA.begin(),numsA.end());
    sort(numsB.begin(),numsB.end());
    int min_ =  INT_MAX;  
    int i = 0, j = 0;
    while (i < numsA.size() && j < numsB.size()) {
        min_ = min(min_, abs(numsA[i] - numsB[j])); //记录其差值，保存最小的差值
        if (numsA[i] < numsB[j]) {
            i++;
        } else {
            j++;
        }
    }
    return min_;
}

int main()
{
    vector<int> numsa = {3,4,6,7};
    vector<int> numsb = {2,3,8,9};
    vec_print(numsa);
    vec_print(numsb);
    int res = smallestDifference(numsa,numsb);
    cout << "res is " << res << endl;
    return 0;
}
