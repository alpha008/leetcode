#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<deque>
#include<stack>
using namespace std;
/**********************************************************************************************************
 最长有效括号
Given a string containing just the characters ’(’ and ’)’, find the length of the longest valid (wellformed) 
parentheses substring.
For ”(()”, the longest valid parentheses substring is ”()”, which has length = 2.
Another example is ”)()())”, where the longest valid parentheses substring is ”()()”, which has length = 4.
**********************************************************************************************************/
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0, n = s.size();
        stack<int > st;
        for(int i = 0;i < n;i++){
            if(s[i] == '(')
                st.push(i);  // 这里左括号是连续入栈的
            else if(s[i] == ')'){
                if(st.empty()){  
                    start = i + 1;     // 更新起始位置 要去掉当前的 ( 位置
                }else{
                    st.pop();          // 弹出栈后，栈顶存储的为与i相匹配的括号的前一个位置
                    res = st.empty() ? max(res , i - start + 1) : max(res, i - st.top());   
                }  // 如果为空，需要借助 start存储的与当前i匹配的左括号的下标计算
                // 如果不为空，栈顶存储的是与当前i匹配的左括号的前一个位置(与当前i匹配的位置已经被弹出)
            }
    }
    return res;  //左边来了压栈，右边来了计算
    }
};           
int main()
{
    string str2 = "()())";
    cout << "valde bracet length is : " << longestValidParentheses(str2) << endl;
    return 0;
}

