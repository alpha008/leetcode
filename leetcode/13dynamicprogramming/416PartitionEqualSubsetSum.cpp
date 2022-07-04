#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include"helpvector.h"
using namespace std;
/********************************************************************************************************
1. 确定dp数组以及下标的含义
对于背包问题，有⼀种写法， 是使⽤⼆维数组，即dp[i][j] 表示从下标为[0-i]的物品⾥任意取，放进容量为j的背包，价值总和最⼤是多少。
只看这个⼆维数组的定义，⼤家⼀定会有点懵，看下⾯这个图
要时刻记着这个dp数组的含义，下⾯的⼀些步骤都围绕这dp数组的含义进⾏的，如果哪⾥看懵了，就来回顾⼀下i代表什么， j⼜代表什么。
2. 确定递推公式
再回顾⼀下dp[i][j]的含义：从下标为[0-i]的物品⾥任意取，放进容量为j的背包，价值总和最⼤是多少。
那么可以有两个⽅向推出来dp[i][j]，
由dp[i - 1][j]推出，即背包容量为j，⾥⾯不放物品i的最⼤价值，此时dp[i][j]就是dp[i - 1][j]
由dp[i - 1][j - weight[i]]推出， dp[i - 1][j - weight[i]] 为背包容量为j - weight[i]的时候不放物品i的最
⼤价值，那么dp[i - 1][j - weight[i]] + value[i] （物品i的价值），就是背包放物品i得到的最⼤价值
所以递归公式： dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
3. dp数组如何初始化
关于初始化，⼀定要和dp数组的定义吻合，否则到递推公式的时候就会越来越乱。
⾸先从dp[i][j]的定义触发，如果背包容量j为0的话，即dp[i][0]，⽆论是选取哪些物品，背包价值总和⼀
定为0。如图：
在看其他情况。
状态转移⽅程 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]); 可以看出i 是由 i-1 推导出来，
那么i为0的时候就⼀定要初始化。
dp[0][j]，即： i为0，存放编号0的物品的时候，各个容量的背包所能存放的最⼤价值。
代码如下：
⼤家应该发现，这个初始化为什么是倒叙的遍历的？正序遍历就不⾏么？
正序遍历还真就不⾏， dp[0][j]表示容量为j的背包存放物品0时候的最⼤价值，物品0的价值就是15，因
为题⽬中说了每个物品只有⼀个！ 所以dp[0][j]如果不是初始值的话，就应该都是物品0的价值，也就是15。
但如果⼀旦正序遍历了，那么物品0就会被重复加⼊多次！ 例如代码如
dp[i][j]表示的是在物品 0-i中任意取出，放进背包大小为j中的最大价值
****************************************************************************************/
void test01BagProblem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    // ⼆维数组
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));
    matrix_print(dp);
    // 初始化
    for (int j = bagWeight; j >= weight[0]; j--) {
        dp[0][j] = dp[0][j - weight[0]] + value[0];
    }
    matrix_print(dp);
    // weight数组的⼤⼩ 就是物品个数
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= bagWeight; j++) { // 遍历背包容量
            if (j < weight[i]) 
            {
                dp[i][j] = dp[i - 1][j];  //如果背包容量小于物品i那么放不下
            }
            else
            {                   // 可以放得下物品i那么就取，放置或者不放置物品i的最大值
                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[weight.size() - 1][bagWeight] << endl;
}
// 二维状态方程修改为一维，需要将遍历顺序修改
void test_1_wei_bag_problem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}
/*************************************************************************************************
给定⼀个只包含正整数的⾮空数组。是否可以将这个数组分割成两个⼦集，使得两个⼦集的元素和相
等。
注意:
每个数组中的元素不会超过 100
数组的⼤⼩不会超过 200
示例 1:
输⼊: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
示例 2:
输⼊: [1, 2, 3, 5]
输出: false

动规五部曲分析如下：
1. 确定dp数组以及下标的含义
    01背包中， dp[i] 表示： 容量为j的背包，所背的物品价值可以最⼤为dp[j]。
    套到本题， dp[i]表示 背包总容量是i，最⼤可以凑成i的⼦集总和为dp[i]。
2. 确定递推公式
    01背包的递推公式为： dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

    本题，相当于背包⾥放⼊数值，那么物品i的重量是nums[i]，其价值也是nums[i]。
    所以递推公式： dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
3. dp数组如何初始化
    在01背包，⼀维dp如何初始化，已经讲过，
    从dp[j]的定义来看，⾸先dp[0]⼀定是0。
    如果如果题⽬给的价值都是正整数那么⾮0下标都初始化为0就可以了，如果题⽬给的价值有负数，那么
    ⾮0下标就要初始化为负⽆穷。
    这样才能让dp数组在递归公式的过程中取的最⼤的价值，⽽不是被初始值覆盖了。
    本题题⽬中 只包含正整数的⾮空数组，所以⾮0下标的元素初始化为0就可以了。
    代码如下：
4. 确定遍历顺序
    在动态规划：关于01背包问题，你该了解这些！（滚动数组） 中就已经说明：如果使⽤⼀维dp数组，物
    品遍历的for循环放在外层，遍历背包的for循环放在内层，且内层for循环倒叙遍历！
    代码如下：
5. 举例推导dp数组
    dp[i]的数值⼀定是⼩于等于i的。
    如果dp[i] == i 说明，集合中的⼦集总和正好可以凑成总和i，理解这⼀点很重要。
    ⽤例1，输⼊[1,5,11,5] 为例，如图：
********************************************************************************************************/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};


int main()
{
    test01BagProblem();

    vector<int> nums = {1, 5, 11, 5};

    cout << "hello " << endl;
    return 0;
}
