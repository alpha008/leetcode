#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，
并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 动态规划：
设置一个与grid[]数组一样大的dp[]数组;
dp[i][j]中储存着从grid[0][0]走到grid[i][j]能获得的礼物的最大值;
(1)初始化dp[0][0]=grid[0][0];
(2)初始化dp[]数组的第一行和第一列;
(3)计算出dp[]数组的其他位置的值;
则礼物的最大值就储存在dp[]数组的右下角，即dp[row-1][col-1];

作者：chang-kong-wu-ming
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/solution/jian-zhi-offer-47-li-wu-de-zui-da-jie-zh-sy4d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 */

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) 
    {
        int row=grid.size();//grid数组的行数
        int col=grid[0].size();//grid数组的列数
        int dp[row][col];//设置dp[]数组的大小为：与grid数组一样大
        //接下来初始化dp[]数组的第一行
        dp[0][0]=grid[0][0];
        for(int i=0,j=1;j<col;j++)
        {
            dp[i][j]=grid[i][j]+dp[i][j-1];
        }
        //接下来初始化dp[]数组的第一列
        for(int j=0,i=1;i<row;i++)
        {
            dp[i][j]=grid[i][j]+dp[i-1][j];
        }
        //接下来更新dp[]数组的其他值，从dp[1][1]到dp[row-1][col-1]。
        //礼物的最大价值储存在dp[row-1][col-1]中
        //更新的算法为：dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[row-1][col-1];
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