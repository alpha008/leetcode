#include<iostream>
#include<algorithm>
using namespace std;
//125. Valid Palindrome
/*****************************************************
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
******************************************************/

//判断字符变量c是否为字母或数字，若是则返回非零，否则返回零。

class Solution {
public:
    bool isPalindrome(string s) 
    {   // 起始位置  结束位置  处理结果存储位置   操作
        transform(s.begin(), s.end(), s.begin(),::tolower); 
        auto left = s.begin(), right = prev(s.end());
        while(left < right)
        {
            if(!::isalnum(*left))  
                left ++;
            else if(!::isalnum(*right)) 
                right --;
            else if(*left++ != *right--) 
                return false;
        }
        return true;
    }
};

class Solution1 {
public:
    bool isPalindrome(string s) {
        bool res = false;
        string newStr;
        for (auto ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')  /* 将大写字母转为小写 */
                newStr.push_back(ch - ('A' - 'a'));
            if ((ch <= 'z' && ch >= 'a') || (ch <= '9' && ch >= '0')) /* 将小写字母和数字加入newStr */
            {
                newStr.push_back(ch);
            }          
        }
        string temp = newStr;
        reverse(newStr.begin(), newStr.end());
        if (newStr == temp)  /* 如果反转前与反转后相等, 则返回true */
            res = true;
        return res;
    }
};

int main()
{
    string str = "0P";
    Solution ab;
    bool flag = ab.isPalindrome(str);
    cout << "is palindrome " << flag << endl;
    cout << "hello " << endl;
    return 0;
}