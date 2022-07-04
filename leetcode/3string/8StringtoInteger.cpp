#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
/****************************************************************************************
1.读入字符串并丢弃无用的前导空格
2.检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 
    确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
3. 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
4. 将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。
如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
5. 如果整数 数值 超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。
具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。 返回整数作为最终结果。

链接：https://leetcode-cn.com/problems/string-to-integer-atoi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
******************************************************************************************/
int myAtoi(string s) {
    int i = 0;
    int sign = 1;
    int result = 0;
    if (s.length() == 0) return 0;
    // 过滤空格
    while (i < s.length() && s[i] == ' ')
    {
        i++; 
    }
    // Check if optional sign if it exists
    if (i < s.length() && (s[i] == '+' || s[i] == '-'))
    { 
        sign = (s[i++] == '-') ? -1 : 1; //后置位++，下次就移动到下一个位置了
    }
    // Build the result and check for overflow/underflow condition  在计算结果之前需要判断是否越界
    while (i < s.length() && s[i] >= '0' && s[i] <= '9') {  // +12345  -12345
        if (result > INT32_MAX / 10 ||   (result == INT32_MAX / 10 && s[i] - '0' > INT32_MAX % 10)) 
        {
            return (sign == 1) ? INT32_MAX : INT32_MIN;
        }
        result = result * 10 + (s[i++] - '0');
    }
    return result * sign;
}

int main()
{
    string s ="    +1234";
    cout <<"result is :" <<  myAtoi(s) << endl;
    return 0;
}





/*
Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
Example 3:

Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
Example 4:

Input: s = "words and 987"
Output: 0
Explanation:
Step 1: "words and 987" (no characters read because there is no leading whitespace)
         ^
Step 2: "words and 987" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "words and 987" (reading stops immediately because there is a non-digit 'w')
         ^
The parsed integer is 0 because no digits were read.
Since 0 is in the range [-231, 231 - 1], the final result is 0.
Example 5:

Input: s = "-91283472332"
Output: -2147483648
Explanation:
Step 1: "-91283472332" (no characters read because there is no leading whitespace)
         ^
Step 2: "-91283472332" ('-' is read, so the result should be negative)
          ^
Step 3: "-91283472332" ("91283472332" is read in)
                     ^
The parsed integer is -91283472332.
Since -91283472332 is less than the lower bound of the range [-231, 231 - 1], the final result is clamped to -231 = -2147483648.
*/