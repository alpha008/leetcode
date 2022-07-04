#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/****************************************************************************************
描述
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought
through this!
If the integer’s last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then
the reverse of 1000000003 overflows. How should you handle such cases?
throw an exception? Good, but what if throwing an exception is not an option? You would then have
to re-design the function (ie, add an extra parameter)
*****************************************************************************************/
//LeetCode, Reverse Integer
// 时间复杂度 O(logn)，空间复杂度 O(1)
class Solution {
public:
    int reverse (int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < INT32_MIN / 10 || rev > INT32_MAX / 10) {
                return 0;  // 判断是否越界
            }
            int digit = x % 10;  // 取出最后一位置
            x /= 10;  // 剔除最后一位
            rev = rev * 10 + digit;
        }
        return rev;
    }
};
int main()
{
    int x = 5679324;
    Solution ab;
    int res = ab.reverse(x);
    cout << "x:" << x << "  res " << res << endl;
    return 0;
}