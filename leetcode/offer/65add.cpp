#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
示例:

输入: a = 1, b = 1
输出: 2


作者：wcs-2
链接：https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/ji-zhu-wei-yun-suan-ye-bu-cuo-by-wcs-2-3fs9/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    int add(int a, int b) {
        while( b ){
            int Sumof_noJinWei= a ^ b; //a异或b为无进位求和
            //a & b后哪个位上是1，则该位相加会产生进位，而进位是左移后的结果。为保险我们强制转换为无符号整型
            int jinWei= (unsigned int)( a & b ) << 1; 

            a=Sumof_noJinWei;
            b=jinWei;//直到没有进位了，得到结果

        }
        return a;
    }
};




int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}