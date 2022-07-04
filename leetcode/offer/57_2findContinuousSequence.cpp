#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include"helpvector.h"
using namespace std;
/*******************************************************************************************************
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
题目条件限定了，至少有两个数字；9 = 4 +  5 | 8 = 3 + 5 | 2 6  由于连续 35 26 都不是
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
示例 1：
输入：target = 9
输出：[[2,3,4],[4,5]]

示例 2：
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*******************************************************************************************************/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        int left = 1, right = 1, sumwindow = 0;
        for(; right <= target / 2 +1 ; right ++ )
        {
            sumwindow = sumwindow + right;  // 加入后小于target，那么right可以继续向右加
            while (sumwindow > target)
            {
                sumwindow = sumwindow - left; // 收缩左边界
                left++; // 同时更新左边界起始位置
            }
            if(sumwindow == target && left != right)
            {
                vector<int> temp;
                for(int i = left; i <= right; i++)
                {
                    temp.push_back(i);
                }
                result.push_back(temp);
            }
        }

        return result;
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