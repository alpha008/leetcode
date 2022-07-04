#include<iostream>
#include<vector>
#include"helpvector.h"
using namespace std;
/***************************************************************************************
 * 返回杨辉三角的第k行
 [
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1]
]
Given an index k, return the kth row of the Pascal’s triangle.
For example, given k = 3,
Return [1,3,3,1].
Note: Could you optimize your algorithm to use only O(k) extra space?
***************************************************************************************/
vector<int> getRow(int rownum)
{
    vector<int> array;
    for(int i =  0; i <= rownum; i++)
    {
        for(int j = i - 1; j > 0 ; j--)
        {   // 从每一行的最后一个位置开始更新
            array[j] = array[j] + array[j - 1];
        }// 最后在末尾加上1
        array.push_back(1);
    }
    return array;
}

int main()
{
    vector<int> res;
    res = getRow(3);
    vec_print(res);
    cout << "hello " << endl;
    return 0;
}