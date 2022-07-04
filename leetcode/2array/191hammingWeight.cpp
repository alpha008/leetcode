#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
示例 2：

输入：00000000000000000000000010000000
输出：1
解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
示例 3：

输入：11111111111111111111111111111101
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
观察这个运算：n~\&~(n - 1)n & (n−1)，其运算结果恰为把 nn 的二进制位中的最低位的 11 变为 00 之后的结果。

如：6~\&~(6-1) = 4, 6 = (110)_2, 4 = (100)_26 & (6−1)=4,6=(110) 
2,4=(100) 2，运算结果 44 即为把 66 的二进制位中的最低位的 11 变为 00 之后的结果。

这样我们可以利用这个位运算的性质加速我们的检查过程，在实际代码中，我们不断让当前的 nn 与 n - 1n−1 做与运算，直到 nn 变为 00 即可。因为每次运算会使得 nn 的最低位的 11 被翻转，因此运算次数就等于 nn 的二进制位中 11 的个数。

*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            n &= n - 1;
            ret++;
        }
        return ret; 
    }
};
int main()
{
    vector<int> nums = {1,2,3,45,6};
    int n = 3;
    Solution ab;
    ab.hammingWeight(n);
    cout << "hello " << endl;
    return 0;
}