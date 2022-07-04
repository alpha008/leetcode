#include <iostream>
#include <string>
using namespace std;
/************************************************************
Input: a = "11", b = "1"
Output: "100"
Input: a = "1010", b = "1011"
Output: "10101"
二进制加法
************************************************************/
string addBinary(string a, string b) 
{
    int carry = 0;
    string result;     
    int indexa  = a.size() -1;
    int indexb  = b.size() -1;
    for(;indexa >= 0 || indexb >= 0 ;indexa --, indexb --)
    {
        int ai = indexa >= 0 ? a[indexa] - '0' : 0;
        int bi = indexb >= 0 ? b[indexb] - '0' : 0;    
        const int val = (ai + bi + carry) % 2;
        carry = (ai + bi + carry  ) / 2;
        result.insert(result.begin(),val + '0');
    }
    if(carry > 0)  // 如果有进位，在前面插入1
        result.insert(result.begin(), '1');
    return result;
}

string test(string a1, string a2)
{
    int m = a1.size() - 1;
    int n = a2.size() - 1;
    string res;
    int carry = 0;
    for(; m >= 0 || n >= 0 ; m--,n--)
    {
        int ai = m >= 0 ? a1[m] - '0' : 0;  //减0是取当前值
        int bi = n >= 0 ? a2[n] - '0' : 0;
        const int val = (ai + bi + carry) % 2;
        carry = (ai + bi + carry) /2 ;
        res.insert(res.begin(), val + '0'); // val + '0' 求的是字符移动
    }
    if(carry > 0)
        res.insert(res.begin(), '1');
    return res;
}
int main()
{
    cout << "+0 " << '0' + '0' << endl;
    cout << "-0 " << '0' - '0' << endl;
    string str1 = "00110";
    string str2 = "11001";
    string res = test(str1, str2);
    cout << "result is " << res << endl;
    cout << "hello " << endl;
    return 0;
}