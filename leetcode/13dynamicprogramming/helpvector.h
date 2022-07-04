#include<iostream>
#include<vector>
using namespace std;
void vec_print(const vector<int> &nums)
{
    cout << "vec is ";
    for(int index = 0; index < nums.size(); index++)
    {
        cout << nums[index] << " " ;
    }
    cout << endl;
}
//遍历二维数组
void matrix_print(const vector<vector<int>>& matrix)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j ++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}
void matrix_print_long(const vector<vector<long>>& matrix)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j ++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}