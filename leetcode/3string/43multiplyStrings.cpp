#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
using namespace std;
/*************************************************************************************************
描述
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note:  numbers can be arbitrarily large and are non-negative.
分析
高精度乘法。
常见的做法是将字符转化为一个 int，一一对应，形成一个 int 数组。但是这样很浪费空间，一
个 int32 的最大值是 231 − 1 = 2147483647，可以与 9 个字符对应，由于有乘法，减半，则至少可以
与 4 个字符一一对应。一个 int64 可以与 9 个字符对应。
Example 1:
    Input: num1 = "2", num2 = "3"
    Output: "6"
Example 2:
    Input: num1 = "123", num2 = "456"
    Output: "56088"

// 9 个字符对应一个 int64_t
// 时间复杂度 O(n*m/81)，空间复杂度 O((n+m)/9)
**************************************************************************************************/
/** 大整数类. */
class BigInt {
public:
    BigInt(string s) 
    {
        vector<int64_t> result;
        result.reserve(s.size() / RADIX_LEN + 1);
        for (int i = s.size(); i > 0; i -= RADIX_LEN) { // [i-RADIX_LEN, i)
            int temp = 0;
            const int low = max(i - RADIX_LEN, 0);
            for (int j = low; j < i; j++) {
                temp = temp * 10 + s[j] - '0';
            }
            result.push_back(temp);
        }
        elems = result;
    }

    string toString() 
    {
        stringstream result;
        bool started = false; // 用于跳过前导 0
        for (auto i = elems.rbegin(); i != elems.rend(); i++) {
            if (started) { // 如果多余的 0 已经都跳过，则输出
                result << setw(RADIX_LEN) << setfill('0') << *i;
            } else {
                result << *i;
                started = true; // 碰到第一个非 0 的值，就说明多余的 0 已经都跳过
            }
        }
        if (!started) return "0"; // 当 x 全为 0 时
        else return result.str();
    }
    static BigInt multiply(const BigInt &x, const BigInt &y) {
        vector<int64_t> z(x.elems.size() + y.elems.size(), 0);
        for (size_t i = 0; i < y.elems.size(); i++) 
        {
            for (size_t j = 0; j < x.elems.size(); j++) 
            { // 用 y[i] 去乘以 x 的各位   // 两数第 i, j 位相乘，累加到结果的第 i+j 位      
                z[i + j] += y.elems[i] * x.elems[j];
                if (z[i + j] >= BIGINT_RADIX) { // 看是否要进位
                    z[i + j + 1] += z[i + j] / BIGINT_RADIX; // 进位
                    z[i + j] %= BIGINT_RADIX;
                }
            }
        }
        while (z.back() == 0) z.pop_back(); // 没有进位，去掉最高位的 0
        return BigInt(z);
    }
private:
    typedef long long int64_t;
    /* 一个数组元素对应 9 个十进制位，即数组是亿进制的  因为 1000000000 * 1000000000 没有超过 2^63-1 */
    const static int BIGINT_RADIX = 1000000000;
    const static int RADIX_LEN = 9;
    /** 万进制整数. */
    vector<int64_t> elems;
    BigInt(const vector<int64_t> num) : elems(num)  {   }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        BigInt x(num1);
        BigInt y(num2);
        return BigInt::multiply(x, y).toString();
    }
};

int main()
{
    string num1 ="123";
    string num2 ="456";
    Solution ab;
    cout <<"result is :" <<  ab.multiply(num1, num2) << endl;
    return 0;
}


