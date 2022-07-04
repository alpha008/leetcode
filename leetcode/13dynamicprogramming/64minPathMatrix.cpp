/******************************************************************************
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小

示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
********************************************************************************/
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include"helpvector.h"
using namespace std;
int minPathSum(vector<vector<int>>& grid) {

    vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(),INT32_MAX ));
    dp[0][0] = grid[0][0];
    for(int i = 0 ; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(i - 1 >= 0  ){// 从上方       
                dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j] );
            }
            if(j - 1 >= 0){  // 从左边
                dp[i][j] = min(dp[i][j-1] + grid[i][j], dp[i][j] );
            }
        }
    }
    matrix_print(dp);
    return dp[grid.size() -1][grid[0].size()-1];
}
int main()
{

    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    matrix_print(grid);
    int res = minPathSum(grid);
    cout << "res is " << res << endl;
    cout << "hello" << endl;
}

