#include<iostream>
#include<vector>
#include"helpvector.h"
using namespace std;
/********************************************************************************************************
给定⼀个⾮负整数数组， a1, a2, ..., an, 和⼀个⽬标数， S。现在你有两个符号 + 和 -。对于数组中的任意
⼀个整数，你都可以从 + 或 -中选择⼀个符号添加在前⾯。
返回可以使最终数组和为⽬标数 S 的所有添加符号的⽅法数。
示例：
输⼊： nums: [1, 1, 1, 1, 1], S: 3
输出： 5
解释：
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
⼀共有5种⽅法让最终⽬标和为3。
事实确实如此，下⾯我也会给出相应的代码，只不过会超时，哈哈。
这道题⽬咋眼⼀看和动态规划背包啥的也没啥关系。
本题要如何使表达式结果为target，
既然为target，那么就⼀定有 left组合 - right组合 = target。
left + right等于sum，⽽sum是固定的。
公式来了， left - (sum - left) = target -> left = (target + sum)/2 。
target是固定的， sum是固定的， left就可以求出来。
如何转化为01背包问题呢。
假设加法的总和为x，那么减法对应的总和就是sum - x。
所以我们要求的是 x - (sum - x) = S
x = (S + sum) / 2
此时问题就转化为，装满容量为x背包，有⼏种⽅法。
⼤家看到(S + sum) / 2 应该担⼼计算的过程中向下取整有没有影响。
这么担⼼就对了，例如sum 是5， S是2的话其实就是⽆解的，所以：
看到这种表达式，应该本能的反应，两个int相加数值可能溢出的问题，当然本题并没有溢出。
再回归到01背包问题，为什么是01背包呢？
因为每个物品（题⽬中的1）只⽤⼀次！
这次和之前遇到的背包问题不⼀样了，之前都是求容量为j的背包，最多能装多少。
本题则是装满有⼏种⽅法。其实这就是⼀个组合问题了。
1. 确定dp数组以及下标的含义
dp[j] 表示：填满j（包括j）这么⼤容积的包，有dp[i]种⽅法
其实也可以使⽤⼆维dp数组来求解本题， dp[i][j]：使⽤ 下标为[0, i]的nums[i]能够凑满j（包括j）这么⼤
容量的包，有dp[i][j]种⽅法。
下⾯我都是统⼀使⽤⼀维数组进⾏讲解， ⼆维降为⼀维（滚动数组），其实就是上⼀层拷⻉下来，这个
我在动态规划：关于01背包问题，你该了解这些！（滚动数组） 也有介绍。
2. 确定递推公式
有哪些来源可以推出dp[j]呢？
不考虑nums[i]的情况下，填满容量为j - nums[i]的背包，有dp[j - nums[i]]中⽅法。
那么只要搞到nums[i]的话，凑成dp[j]就有dp[j - nums[i]] 种⽅法。
举⼀个例⼦,nums[i] = 2： dp[3]，填满背包容量为3的话，有dp[3]种⽅法。
那么只需要搞到⼀个2（nums[i]），有dp[3]⽅法可以凑⻬容量为3的背包，相应的就有多少种⽅法可以
凑⻬容量为5的背包
那么需要把 这些⽅法累加起来就可以了， dp[i] += dp[j - nums[i]]
所以求组合类问题的公式，都是类似这种：
这个公式在后⾯在讲解背包解决排列组合问题的时候还会⽤到！
3. dp数组如何初始化
从递归公式可以看出，在初始化的时候dp[0] ⼀定要初始化为1，因为dp[0]是在公式中⼀切递推结果的
起源，如果dp[0]是0的话，递归结果将都是0。
dp[0] = 1，理论上也很好解释，装满容量为0的背包，有1种⽅法，就是装0件物品。
dp[j]其他下标对应的数值应该初始化为0，从递归公式也可以看出， dp[j]要保证是0的初始值，才能正确
的由dp[j - nums[i]]推导出来。
4. 确定遍历顺序
在动态规划：关于01背包问题，你该了解这些！（滚动数组） 中，我们讲过对于01背包问题⼀维dp的遍
历， nums放在外循环， target在内循环，且内循环倒序。
5. 举例推导dp数组
输⼊： nums: [1, 1, 1, 1, 1], S: 3
bagSize = (S + sum) / 2 = (3 + 5) / 2 = 4

****************************************************************************************/
class Solution {
public:
    int count = 0;

    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }

    void backtrack(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                count++;
            }
        } else {
            backtrack(nums, target, index + 1, sum + nums[index]);
            backtrack(nums, target, index + 1, sum - nums[index]);
        }
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};

    cout << "hello " << endl;
    return 0;
}
