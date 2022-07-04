
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<limits.h>
#include<string>
#include<unordered_map>
#include"helpvector.h"
using namespace std;
/***********************************************************************************************
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
示例 1:
输入: s = "aba"
输出: true
示例 2:
输入: s = "abca"
输出: true
解释: 你可以删除c字符。
示例 3:

输入: s = "abc"
输出: false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***********************************************************************************************/
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;              // 左指针
        int right = s.size() -1;   // 右指针
        while(left < right)
        {
            if(s[left] != s[right]){
                return isPalindromic(s, left+1, right) || isPalindromic(s, left, right-1);
            }  // 删除左边或者右边
            left++;
            right--;
        }
        return true;
    }
    // 判断似乎是回文串
    bool isPalindromic(string s , int left,int right)
    {
        while(left < right){
            if(s[left++] !=  s[right--]){
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string s = "eceba";

    cout << "s: " << s << endl;
    Solution ab;
    
    bool res = ab.validPalindrome(s);
    cout << "res is " << res << endl;
    return 0;
}
