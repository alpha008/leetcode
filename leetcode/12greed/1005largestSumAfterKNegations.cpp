#include<iostream>
#include<algorithm>
#include<vector>
#include"helpvector.h"
using namespace std;
/*********************************************************************************************
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
https://leetcode-cn.com/circle/article/qiAgHn/
*********************************************************************************************/
class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp); // 第⼀步
        for (int i = 0; i < A.size(); i++) { // 第⼆步
            if (A[i] < 0 && K > 0) 
            {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1)
            A[A.size() - 1] *= -1; // 第三步
        int result = 0;
        for (int a : A) 
            result += a; // 第四步
        return result;
    }
};
int main()
{   
    vector<int> pricces = {7,1,5,3,6,4};
    vec_print(pricces);
    Solution ab;

    cout << "hello " << endl;
    return 0;
}