#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<deque>
#include "helpvector.h"
using namespace std;

/***********************************************************************
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，s1 的排列之一是 s2 的 子串 。
示例 1：
输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
示例 2：

输入：s1= "ab" s2 = "eidboaoo"
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
方法一：滑动窗口
由于排列不会改变字符串中每个字符的个数，所以只有当两个字符串每个字符的个数均相等时，一个字符串才是另一个字符串的排列。

根据这一性质，记 s_1s 
1
​
  的长度为 nn，我们可以遍历 s_2s 
2
​
  中的每个长度为 nn 的子串，判断子串和 s_1s 
1
​
  中每个字符的个数是否相等，若相等则说明该子串是 s_1s 
1
​
  的一个排列。

使用两个数组 \textit{cnt}_1cnt 
1
​
  和 \textit{cnt}_2cnt 
2
​
 ，\textit{cnt}_1cnt 
1
​
  统计 s_1s 
1
​
  中各个字符的个数，\textit{cnt}_2cnt 
2
​
  统计当前遍历的子串中各个字符的个数。

由于需要遍历的子串长度均为 nn，我们可以使用一个固定长度为 nn 的滑动窗口来维护 \textit{cnt}_2cnt 
2
​
 ：滑动窗口每向右滑动一次，就多统计一次进入窗口的字符，少统计一次离开窗口的字符。然后，判断 \textit{cnt}_1cnt 
1
​
  是否与 \textit{cnt}_2cnt 
2
​
  相等，若相等则意味着 s_1s 
1
​
  的排列之一是 s_2s 
2
​
  的子串。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
************************************************************************/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) {
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = n; i < m; ++i) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }
};

int main()
{


    return 0;
}
