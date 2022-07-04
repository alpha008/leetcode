#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*******************************************************************************************
 * 示例 1：
输⼊： "abc"
输出： 3
解释：三个回⽂⼦串: "a", "b", "c"
示例 2：
输⼊： "aaa"
输出： 6
解释： 6个回⽂⼦串: "a", "a", "a", "aa", "aa", "aaa"
动规五部曲：
1. 确定dp数组（dp table）以及下标的含义
    布尔类型的dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的⼦串是否是回⽂⼦串，如果是dp[i][j]为
    true，否则为false
2. 确定递推公式
    在确定递推公式时，就要分析如下⼏种情况。
    整体上是两种，就是s[i]与s[j]相等， s[i]与s[j]不相等这两种。
    当s[i]与s[j]不相等，那没啥好说的了， dp[i][j]⼀定是false。
    当s[i]与s[j]相等时，这就复杂⼀些了，有如下三种情况
    情况⼀：下标i 与 j相同，同⼀个字符例如a，当然是回⽂⼦串
    情况⼆：下标i 与 j相差为1，例如aa，也是⽂⼦串
    情况三：下标： i 与 j相差⼤于1的时候，例如cabac，此时s[i]与s[j]已经相同了，我们看i到j区间是
    不是回⽂⼦串就看aba是不是回⽂就可以了，那么aba的区间就是 i+1 与 j-1区间，这个区间是不是
    回⽂就看dp[i + 1][j - 1]是否为true。
    以上三种情况分析完了，那么递归公式如下：
    result就是统计回⽂⼦串的数量。
    注意这⾥我没有列出当s[i]与s[j]不相等的时候，因为在下⾯dp[i][j]初始化的时候，就初始为false。
3. dp数组如何初始化
    dp[i][j]可以初始化为true么？ 当然不⾏，怎能刚开始就全都匹配上了。
    所以dp[i][j]初始化为false。
4. 确定遍历顺序
    遍历顺序可有有点讲究了。
    ⾸先从递推公式中可以看出，情况三是根据dp[i + 1][j - 1]是否为true，在对dp[i][j]进⾏赋值true的。
    dp[i + 1][j - 1] 在 dp[i][j]的左下⻆，
    如果这矩阵是从上到下，从左到右遍历，那么会⽤到没有计算过的dp[i + 1][j - 1]，也就是根据不确定是
    不是回⽂的区间[i+1,j-1]，来判断了[i,j]是不是回⽂，那结果⼀定是不对的。
    所以⼀定要从下到上，从左到右遍历，这样保证dp[i + 1][j - 1]都是经过计算的。
    有的代码实现是优先遍历列，然后遍历⾏，其实也是⼀个道理，都是为了保证dp[i + 1][j - 1]都是经过计算的。
********************************************************************************************/
class Solution {
public:
    int countSubstrings(const string s)
    {
        if(s.empty()) return 0;
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() -1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if(s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
                {
                    result++;
                    dp[i][j] = true;    
                }
            }
        }
        return result;
    }
};


int main()
{
    string s = "abc";


    cout << "hello " << endl;
    return 0;
}