#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/********************************************************************************************
给定两个字符串, A 和 B。
A 的旋转操作就是将 A 最左边的字符移动到最右边。 
例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后，A 能变成B，那么返回True。

示例 1:
输入: A = 'abcde', B = 'cdeab'
输出: true

示例 2:
输入: A = 'abcde', B = 'abced'
输出: false
**********************************************************************************************/
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size())
        {
            return false;
        }
        A += A;
        return A.find(B) != string::npos;
    }
};



int main()
{

    cout << "hello " << endl;
    return 0;
}