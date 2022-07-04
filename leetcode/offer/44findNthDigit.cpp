#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

 

示例 1：

输入：n = 3
输出：3
示例 2：

输入：n = 11
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    double getcount(int digits){ //计算digits有多少位
        if(digits==1) return 10;
        return 9*pow(10,digits-1);
    }
    int startNum(int digits){  //计算digits位开始的数字
        if(digits==1) return 0;
        return pow(10,digits-1);
    }
    int find(int n,int digits){    //在digits位里寻找第n位
        int number=startNum(digits)+n/digits;  //要查找的数字
        int index_right=digits-n%digits;    //要找的是第n%digits位，用该句从右开始查找。
        for(int i=1;i<index_right;i++){
            number/=10;
        }
        return number%10;
    }
    int findNthDigit(int n) {
        int digits=1;
        while(1){
            double num=getcount(digits);
            if(n<num*digits){
                return find(n,digits);
            }
            n-=num*digits;
            digits++;
        }
        return -1;
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