#include<iostream>
#include<vector>
#include<string>

using namespace std;
/*
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方
（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
示例：
输入: 10
输出: 4
解释: 
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotated-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int rotatedDigits(int N) {
        string A = to_string(N);
        int K = A.size();
        /*
        equality_flag 表示已经写出的 j 位数字是否等于 N 的 j 位前缀；
        involution_flag 表示从最高位到比当前位高一位的这段前缀中是否含有 2569 中的任意一个数字。
        
        dp(i, equality_flag, involution_flag) 
            表示在特定 equality_flag，involution_flag 的状态下，
            有多少种从 i 到末尾的后缀能组成一个好数。
        最终的结果为 dp(0, True, False)。
        */
           
        vector<vector<vector<int>>> memo(K + 1, vector<vector<int>>(2, vector<int>(2, 0)));
        // 第K位 无前缀 匹配的情况下 能够构建
        memo[K][0][1] = memo[K][1][1] = 1;
        // 按位匹配
        for (int i = K - 1; i >= 0; --i) {
            // 前缀是否相等
            for (int eqf = 0; eqf <= 1; ++eqf)
                // 从最高位到比当前位高一位这段前缀，是否有2569
                for (int invf = 0; invf <= 1; ++invf) {
                    int ans = 0;
                    // 前缀相等 从[0, A[i]], 否则从[0, 9]
                    for (char d = '0'; d <= (eqf == 1 ? A[i] : '9'); ++d) {
                        // 347不可能是
                        if (d == '3' || d == '4' || d == '7') continue;
                        // 本位是 2569
                        bool invo = (d == '2' || d == '5' || d == '6' || d == '9');
                        // 第 i 位，前缀是否相等，本位是否是2569
                        ans += memo[i + 1][d == A[i] ? eqf : 0][invo ? 1 : invf];
                    }
                    memo[i][eqf][invf] = ans;
                }
        }
        /*
            计算ans = memo[i][eqf][invf]，
            关于N = A[i:]的良好数字的数量。
                如果eqf为真，我们必须小于N，否则我们可以使用任何数字。
            当写入2569时，Invf为真，并且必须在写入结束时为真，因为所有好的数字都有一位在2569。
        */
        return memo[0][1][0];
    }
};



int main()
{

    cout << "hello " << endl;
    return 0;
}