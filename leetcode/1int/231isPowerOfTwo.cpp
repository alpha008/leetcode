#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include<stack>

#include "helpvector.h"
using namespace std;
/*************************************************************************************************************************
示例 1：
输入：n = 1
输出：true
解释：20 = 1
示例 2：

输入：n = 16
输出：true
解释：24 = 16
链接：https://leetcode-cn.com/problems/power-of-two
*************************************************************************************************************************/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)   return false;
        while (n % 2 == 0)
        {
            n = n /2;
        }
        return n == 1;
    }
};

int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7};
    Solution ab;
    uint32_t n = 110;
    bool res = ab.isPowerOfTwo(n);
    cout << "res " << endl;
    cout << endl;
    
    return 0;
}

