#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

 

示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        // 考虑边缘情况
        if (x == 0 || x == 1.0)
        {
            return x;
        }

        // 考虑溢出的情况
        long b = (long)n;
        if (b < 0)
        {
            b = -b;
            x = 1/x;
        }

        while (b > 0)
        {
            if ((b&1) == 1)
            {
                res *= x;
            }
            x *= x;
            b >>= 1;
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}