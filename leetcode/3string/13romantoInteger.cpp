#include<iostream>
#include<vector>
#include<algorithm>
#include"helpvector.h"

/**************************************************************************************
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
*************************************************************************************/
class Solution {
public:
    inline int map(const char c) {
        switch (c) 
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
            }
        }
        int romanToInt(string s) {
            int result = 0;
            for (size_t i = 0; i < s.size(); i++) {
                if (i > 0 && map(s[i]) > map(s[i - 1])) {
                    result += (map(s[i]) - 2 * map(s[i - 1]));
                } else {
                    result += map(s[i]);
                }
            }   
            return result;
        }
};
int main()
{
    string str  = "DM";
    Solution ab;
    int result =  ab.romanToInt(str);
    cout << "str: " << str << " result " << result  << endl; 

    return 0;
}