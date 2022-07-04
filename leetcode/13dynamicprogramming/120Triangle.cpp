#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/***************************************************************************************
给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，
如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
示例 1：
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

示例 2：
输入：triangle = [[-10]]
输出：-10
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
方法一：动态规划
思路与算法

我们用 f[i][j]f[i][j] 表示从三角形顶部走到位置 (i, j)(i,j) 的最小路径和。这里的位置 (i, j)(i,j) 指的是三角形中第 ii 行第 jj 列（均从 00 开始编号）的位置。

由于每一步只能移动到下一行「相邻的节点」上，因此要想走到位置 (i, j)(i,j)，上一步就只能在位置 (i - 1, j - 1)(i−1,j−1) 或者位置 (i - 1, j)(i−1,j)。我们在这两个位置中选择一个路径和较小的来进行转移，状态转移方程为：

f[i][j] = \min(f[i-1][j-1], f[i-1][j]) + c[i][j]
f[i][j]=min(f[i−1][j−1],f[i−1][j])+c[i][j]

其中 c[i][j]c[i][j] 表示位置 (i, j)(i,j) 对应的元素值。

注意第 ii 行有 i+1i+1 个元素，它们对应的 jj 的范围为 [0, i][0,i]。当 j=0j=0 或 j=ij=i 时，上述状态转移方程中有一些项是没有意义的。例如当 j=0j=0 时，f[i-1][j-1]f[i−1][j−1] 没有意义，因此状态转移方程为：

f[i][0] = f[i-1][0] + c[i][0]
f[i][0]=f[i−1][0]+c[i][0]

即当我们在第 ii 行的最左侧时，我们只能从第 i-1i−1 行的最左侧移动过来。当 j=ij=i 时，f[i-1][j]f[i−1][j] 没有意义，因此状态转移方程为：
f[i][i] = f[i-1][i-1] + c[i][i]
f[i][i]=f[i−1][i−1]+c[i][i]
即当我们在第 ii 行的最右侧时，我们只能从第 i-1i−1 行的最右侧移动过来。
最终的答案即为 f[n-1][0]f[n−1][0] 到 f[n-1][n-1]f[n−1][n−1] 中的最小值，其中 nn 是三角形的行数。
细节状态转移方程的边界条件是什么？由于我们已经去除了所有「没有意义」的状态，因此边界条件可以定为：

f[0][0] = c[0][0]
f[0][0]=c[0][0]

即在三角形的顶部时，最小路径和就等于对应位置的元素值。这样一来，我们从 11 开始递增地枚举 ii，并在 [0, i][0,i] 的范围内递增地枚举 jj，
就可以完成所有状态的计算。
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/triangle/solution/san-jiao-xing-zui-xiao-lu-jing-he-by-leetcode-solu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
***************************************************************************************/
class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back()); // 取出最后一行的数值
        for(int i = triangle.size() - 2; i >= 0; i --){
            for(int j = 0; j <= i; j ++){
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];  // 当我们在第 i 行的最左侧时，我们只能从第 i-1 i−1 行的最左侧移动过来
            for (int j = 1; j < i; ++j) { // 中间位置 
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];  // 当我们在第 i 行的最右侧时，我们只能从第 i-1 i−1 行的最右侧移动过来。
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
        // min_element  求给出指定区间内的最小值
    }
};

int main()
{
    vector<vector<int>> nums = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution ab;
    ab.minimumTotal(nums);
    cout << "hello " << endl;
    return 0;
}