
#include<algorithm>
#include<iostream>
#include<limits>
#include<stack>
#include <bitset>

using namespace std;
/**************************************************************************************
观察这个运算 n&(n-1) ,其运算结果恰为把n的二进制位中的最低位的1变为0之后的结果
如： 6 & （6 -1）= 4 ， 6(110) 4(100) 运算结果4即为把6的二进制为中的最低位1变为0之后的结果
这样我们利用这个性质可以加快我们的检查过程，运算次数就等于n的二进制位中1的个数
**************************************************************************************/
int countone(uint32_t num)
{
    int reslut = 0;
    while(num)
    {
        num = num & (num-1);
        reslut++;
    }
    return reslut;
}
int main()
{
    uint32_t target = 3;
    cout << bitset<sizeof(target) * 8>(target) <<endl ;
    cout << "number 1 is :" << countone(target) << endl;
    cout << "hello" << endl;
    return 0;
}