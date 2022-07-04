#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;
/***********************************************************************
判断符号是否是成对存在
***********************************************************************/
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {  //如果栈顶不相等
                    return false;
                }
                stk.pop(); // 如果栈顶相等，那么弹出
            }
            else {  // 左括号入栈
                stk.push(ch);
            }
        }
        return stk.empty(); // 如果栈内无剩余，说明都匹配上了
    }
};
int main()
{
    cout << "hello " << endl;
    return 0;
}