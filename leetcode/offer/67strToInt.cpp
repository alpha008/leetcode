#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>
using namespace std;
/*

作者：RyanWangllng
链接：https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/solution/zhu-shi-xing-ti-jie-bian-li-jian-zhi-67b-hf35/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    int strToInt(string str) {
        int ret = 0; // 转换后的数字
        int flag = 1; // 标记正负号
        int len = str.size();
        if (len <= 0) return ret; // 临界条件
        int index = 0;
        // 遍历字符串，寻找第一个不是空格的字符
        while (str[index] == ' ') {
            ++index;
            // 若全是空格，则直接返回ret
            if (index == len) return ret;
        }
        /*
        *  判断第一个非空格的字符是正号还是负号
        *  正号标记为1，负号标记为-1
        */
        flag = str[index] == '-' ? -1 : 1;
        // 判断完正负号之后，遍历指针继续后移一位
        if (str[index] == '-' || str[index] == '+') ++index;
        /* 
        *  int类型的范围是-2147483648到2147483647
        *  所以设置边界为21474836
        *  这样只要将下一位数字和7相比就能判断该数字是否越界
        */
        int bound = 214748364;
        // 继续遍历
        while (index < len) {
            // 碰到不是数字的字符，忽略即可
            if (str[index] <'0' || str[index] > '9') break;
            // 将当前遍历到的字符转化成数字
            int curr = str[index] - '0';
            /*
            *  越界条件：
            *  1、ret > 214748364，则不用看下一位数字就能断定已经越界了
            *  2、ret = 214748364，则根据下一位数字，若大于7，则越界
            */
            if ((ret > bound) || (ret == bound && curr > 7)) {
                // 根据前面判断的正负号，返回对应的值
                return flag == -1 ? INT_MIN : INT_MAX;
            }
            // 将当前数字并入转化后的数字中
            ret = ret * 10 + curr;
            ++index;
        }
        // 乘上正负号标记，负号乘完之后就是负数
        return ret * flag;
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