#include<iostream>
#include<vector>
#include"helpvector.h"
using namespace std;
/***************************************************************************************
 * 构造杨辉三角
Given numRows, generate the first numRows of Pascal’s triangle.
For example, given numRows = 5,
Return
[
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1]
]
分析
本题可以用队列，计算下一行时，给上一行左右各加一个 0，然后下一行的每个元素，就等于左上角和右上角之和。
另一种思路，下一行第一个元素和最后一个元素赋值为 1，中间的每个元素，等于上一行的左上角和右上角元素之和。

***************************************************************************************/
vector<vector<int>> generate(int numRow)
{
    vector<vector<int>> result;
    if(numRow == 0)
        return result;
    result.push_back(vector<int>(1,1));
    for(int i = 2; i <= numRow ; i ++)
    {
        vector<int> current(i,1); //第几层就有几个1 ，使用1 占位，就有多少个1的元素
        const vector<int> prev = result[i - 2];
        for(int j = 1; j < i - 1; j++)  //遍历每行的 去除首位位置
        {
            current[j] =  prev[j-1] + prev[j];
        }
        result.push_back(current);
    }
    return result;
}
vector<vector<int>> getRow(int rownum)
{
    vector<vector<int>> result(rownum,vector<int>(rownum , 0));
    vector<int> array;
    for(int i = 0; i < rownum; i++)
    {
        for(int j = i - 1; j > 0 ; j--) // j > 0保证不会更新到第一个位置上的元素
        {                                   // 从每一行的最后一个位置开始更新
            array[j] = array[j] + array[j - 1];
        }                                   // 最后在末尾加上1
        array.push_back(1);
        result[i] = array;
    }
    return result;
}
int main()
{
    vector<vector<int>> res;
    res = getRow(4);
    matrix_print(res);
    cout << "hello " << endl;
    return 0;
}