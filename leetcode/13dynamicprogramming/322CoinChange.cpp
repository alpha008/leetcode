#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

/******************************************************************************
给定不同⾯额的硬币 coins 和⼀个总⾦额 amount。编写⼀个函数来计算可以凑成总⾦额所需的最少的
硬币个数。如果没有任何⼀种硬币组合能组成总⾦额，返回 -1。
你可以认为每种硬币的数量是⽆限的。
示例 1：
输⼊： coins = [1, 2, 5], amount = 11
输出： 3
解释： 11 = 5 + 5 + 1
示例 2：
输⼊： coins = [2], amount = 3
输出： -1
示例 3：
输⼊： coins = [1], amount = 0
输出： 0
动规五部曲分析如下：
1. 确定dp数组以及下标的含义
    dp[j]：凑⾜总额为j所需钱币的最少个数为dp[j]
2. 确定递推公式
    得到dp[j]（考虑coins[i]），只有⼀个来源， dp[j - coins[i]]（没有考虑coins[i]）。
    凑⾜总额为j - coins[i]的最少个数为dp[j - coins[i]]，那么只需要加上⼀个钱币coins[i]即dp[j - coins[i]] + 1就是dp[j]（考虑coins[i]）
    所以dp[j] 要取所有 dp[j - coins[i]] + 1 中最⼩的。
    递推公式： dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
3. dp数组如何初始化
    ⾸先凑⾜总⾦额为0所需钱币的个数⼀定是0，那么dp[0] = 0;
    其他下标对应的数值呢？
    考虑到递推公式的特性， dp[j]必须初始化为⼀个最⼤的数，否则就会在min(dp[j - coins[i]] + 1, dp[j])⽐较的过程中被初始值覆盖。  
     所以下标⾮0的元素都是应该是最⼤值。

4. 确定遍历顺序
    本题求钱币最⼩个数， 那么钱币有顺序和没有顺序都可以，都不影响钱币的最⼩个数。 。
    所以本题并不强调集合是组合还是排列。
    如果求组合数就是外层for循环遍历物品，内层for遍历背包。
    如果求排列数就是外层for遍历背包，内层for循环遍历物品。
    在动态规划专题我们讲过了求组合数是动态规划： 
    518.零钱兑换II，求排列数是动态规划： 377. 组合总和 Ⅳ。
    所以本题的两个for循环的关系是：外层for循环遍历物品，内层for遍历背包或者外层for遍历背包，内
    层for循环遍历物品都是可以的！
    那么我采⽤coins放在外循环， target在内循环的⽅式。
    本题钱币数量可以⽆限使⽤，那么是完全背包。所以遍历的内循环是正序
    综上所述，遍历顺序为： coins（物品）放在外循环， target（背包）在内循环。且内循环正序。
5. 举例推导dp数组
以输⼊： coins = [1, 2, 5], amount = 5为例

*********************************************************************************/
// 版本⼆
class Solution {
public:
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) { // 遍历背包
        for (int j = 0; j < coins.size(); j++) { // 遍历物品
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX ) {
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }
    if (dp[amount] == INT_MAX) return -1;
    return dp[amount];
    }
};

int main()
{   
    vector<int> nums = {1,2,5};
    int target = 11;
    Solution ab;
    int res = ab.coinChange(nums, target);
    cout << "res is " << res << endl;
    cout << "hello " << endl;
    return 0;
}
