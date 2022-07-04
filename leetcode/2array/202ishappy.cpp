#include<unordered_set>

#include<iostream>
#include<vector>
/***********************************************************************
写一个算法来判断一个数 n 是不是快乐数。
「快乐数」定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。
示例 1：
输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
示例 2：
输入：n = 2
输出：false
2  4  16 37 58 89 
***********************************************************************/
using namespace std;

bool ishappy(int n)
{   
    unordered_set<int> ss;
    while(n != 1)
    {
        int cursum = 0;
        while(n != 0){
            int cur = n %10;
            cursum += cur * cur;
            n = n/10;
        }
        cout << "cursum " << cursum << endl;
        // 计算的结果和之前重复，那么说明进入死循环，如果等于1那么说明是真的快乐数字了
        if(ss.find(cursum) != ss.end() && cursum != 1) return false;
        ss.insert(cursum);
        n = cursum;
    }
    return true;
}
int main()
{
    int n = 2;
    cout << " n: " << n  << endl;
    int res = ishappy(2);
    cout << "res " << res << endl;

    return 0;
}
