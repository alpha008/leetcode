#include<unordered_set>
#include<iostream>
#include<vector>
using namespace std;
/***********************************************************************
示例 1：

输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。
示例 2：

输入：s = "AABABBA", k = 1
输出：4
解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***********************************************************************/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = s.size();

        vector<int> charCount(26,0);  // 使用数组，数组内初始元素是不确定的，需要初始化
        int left = 0 , right = 0;
        int maxSameCount= 0;
        int maxWindow = 0;

        for(; right < length ; right++)
        {
            maxSameCount = max(maxSameCount , ++charCount[s[right]-'A']); // 依次记录窗口内出现字符次数最多的那个数量
            if( k + maxSameCount < (right - left + 1)){  // 如果最多的次数 + k 还小于 窗口大小，说明不能全部被替换，缩小窗口大小 ，同时左边界更新
                charCount[s[left] - 'A'] --;
                left++;
            }else{ // 说明可以完全替换，那么我们计算最大值
                maxWindow =  max(maxWindow , right -left +1);
            }
        }
        return maxWindow;
    }
};

int main()
{
    string s = "ABAB";
    Solution ab;
    int res = ab.characterReplacement( s, 2);
    cout << "res " << res << endl;

    return 0;
}
