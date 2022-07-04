#include<iostream>
#include<vector>
#include<algorithm>
#include"helpvector.h"

/************************************************************************
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

输入: num = 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
************************************************************************/
class Solution{
public:
    string intToRoman(int num)
    {
        const int radix[] = {1000, 900, 500, 400, 100, 90 , 50, 40, 10, 9 ,5, 4 ,1 };
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC","L", "XL", "X", "IX", "V", "IV", "I"};
        string roman;
        for(int i = 0; num > 0 ; i++)
        {
            int count = num / radix[i];
            num = num % radix[i];
            for(; count > 0 ; --count) roman += symbol[i];
        }
        return roman;
    }
};
int main()
{
    int n = 125;
    Solution ab;
    string str =  ab.intToRoman(n);
    cout << "n: " << n << " str " << str << endl; 

    return 0;
}


