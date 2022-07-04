#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
/******************************************************************************
给定正整数 n，找到若⼲个完全平⽅数（⽐如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完
全平⽅数的个数最少。
给你⼀个整数 n ，返回和为 n 的完全平⽅数的 最少数量 。
完全平⽅数 是⼀个整数，其值等于另⼀个整数的平⽅；换句话说，其值等于⼀个整数⾃乘的积。例如，
1、 4、 9 和 16 都是完全平⽅数，⽽ 3 和 11 不是。
示例 1：
输⼊： n = 12
输出： 3
解释： 12 = 4 + 4 + 4
示例 2：
输⼊： n = 13
输出： 2
解释： 13 = 4 + 9
提示：
1 <= n <= 10^4
动规五部曲分析如下：
1. 确定dp数组（dp table）以及下标的含义
    dp[i]：和为i的完全平⽅数的最少数量为dp[i]
2. 确定递推公式
    dp[j] 可以由dp[j - i * i]推出， dp[j - i * i] + 1 便可以凑成dp[j]
此时我们要选择最⼩的dp[j]，所以递推公式： dp[j] = min(dp[j - i * i] + 1, dp[j]);
3. dp数组如何初始化
    dp[0]表示 和为0的完全平⽅数的最⼩数量，那么dp[0]⼀定是0。
    有同学问题，那0 * 0 也算是⼀种啊，为啥dp[0] 就是 0呢？
    看题⽬描述，找到若⼲个完全平⽅数（⽐如 1, 4, 9, 16, ...），题⽬描述中可没说要从0开始， dp[0]=0完全是为了递推公式。
    ⾮0下标的dp[j]应该是多少呢？
    从递归公式dp[j] = min(dp[j - i * i] + 1, dp[j]);
    中可以看出每次dp[j]都要选最⼩的， 所以⾮0下标的dp[i]⼀定要初始为最⼤值，这样dp[j]在递推的时候才不会被初始值覆盖。
4. 确定遍历顺序
    我们知道这是完全背包，
    如果求组合数就是外层for循环遍历物品，内层for遍历背包。
    如果求排列数就是外层for遍历背包，内层for循环遍历物品。
    在动态规划： 322. 零钱兑换中我们就深⼊探讨了这个问题，本题也是⼀样的，是求最⼩数！
    所以本题外层for遍历背包，⾥层for遍历物品，还是外层for遍历物品，内层for遍历背包，都是可以的！
    我这⾥先给出外层遍历背包，⾥层遍历物品的代码：
5. 举例推导dp数组
已输⼊n为5例， dp状态图如下：
dp[0] = 0
dp[1] = min(dp[0] + 1) = 1
dp[2] = min(dp[1] + 1) = 2
dp[3] = min(dp[2] + 1) = 3
dp[4] = min(dp[3] + 1, dp[0] + 1) = 1
dp[5] = min(dp[4] + 1, dp[1] + 1) = 2
*********************************************************************************/

class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};

int main()
{
    int target = 12;
    Solution ab;
    int res = ab.numSquares(target);
    cout << "res is " << res << endl;
    cout << "hello " << endl;
    return 0;
}