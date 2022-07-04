#include<iostream>
#include<vector>
using namespace std;

/**********************************************
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);
示例 1
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
首先访问 行 0 中的所有字符，接着访问 行 1，然后 行 2，依此类推...
对于所有整数 k
我们先假定有 numRows=4 行来推导下，其中 2*numRows-2 = 6 , 我们可以假定为 step=2*numRows-2 ，我们先来推导下规则：
第0行： 0 - 6 - 12 - 18
==> 下标间距 6 - 6 - 6 ==> 下标间距 step - step - step
第1行： 1 - 5 - 7 - 11 - 13
==> 下标间距 4 - 2 - 4 - 2 ==> 下标间距step-2*1(行)-2*1(行)-step-2*1(行)-2*1(行)
第2行： 2 - 4 - 8 - 10 - 14
==> 下标间距 2 - 4 - 2 - 4 ==> 下标间距step-2*2(行)-2*2(行)-step-2*2(行)-2*2(行)
第3行：3 - 9 - 15 - 21
==> 下标间距间距 6 - 6 - 6 ==>下标间距step - step - step
可以得出以下结论：
起始下标都是行号
第0层和第numRows-1层的下标间距总是step 。
中间层的下标间距总是step-2*行数，2*行数交替。
下标不能超过len(s)-1
**********************************************/
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		int step = numRows * 2 - 2; // 间距
		int index = 0;// 记录s的下标
		int len = s.length();
		int distance = 0; // 真实的间距
		string str;
		for (int i = 0; i < numRows; i++) // i表示行号
		{
			index = i;
			distance = i * 2;
			while (index < len) // 超出字符串长度计算下一层
			{
				str += s[index]; // 当前行的第一个字母
				distance = step - distance;  // step-2*1(行)  - 2*1(行)   交替间距
				index += (i == 0 || i == numRows-1) ? step : distance; // 0行和最后一行使用step间距，其余使用distance间距
                // 更新下表起始位置
			}
		}
		return str;
	}

};
// 最大回文子串
int main()
{
    string  s = "PAYPALISHIRING";
    int numRows = 3;
    cout << "s:" << s << endl;    
    Solution ab;
    string res =  ab.convert(s, numRows);

    cout << "res:" << res << endl;
    cout << "hello " << endl;
    return 0;
} 