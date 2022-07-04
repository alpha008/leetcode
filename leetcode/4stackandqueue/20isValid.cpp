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
1. 判断输入的括号是否有效
Given a string containing just the characters ’(’, ’)’, ’{’, ’}’, ’[’ and ’]’, determine if the input string is valid.
brackets must close in the correct order, ”()” and ”()[]” are all valid but ”(]” and ”([)]” are not.
**********************************************************************************************************/
bool isValid(string const &s){
    string left = "([{";
    string right = ")]}";
    stack<char> stk;// 栈    自动推导类型  auto
    for(auto c : s)
    {
        if(left.find(c) != string::npos)  // 如果是左边符号一直入栈
        { // string没找到是会返回string::npos
            stk.push(c);
           // cout << "c: " << c << " " << endl;
        }else{
            if(stk.empty() || stk.top() != left[right.find(c)])
                return false;   // 潜规则一定是最近匹配
            else
                stk.pop();   
        }
    }
    return stk.empty();
}


bool isValidesymbol(string s)
{
    if(s.empty()) 
        return true;
    stack<char> stk;
    string left  = "{([";
    string right = "})]";
    for(int i =0 ; i < s.size(); i++)
    {
        if(left.find(s[i]) != string::npos){
            stk.push(s[i]);
        }else{
            if(stk.empty() || stk.top() != left[right.find(s[i])]){
                return false;    
            }else{
                stk.pop();
            }
        }
    }
    return stk.empty();  // 当栈不为空说明还有没有匹配成功的符号
}
int main()
{
    //1. 判断输入的括号是否有效
    string str = "([]){}";
    cout << "判断输入的括号是否有效  " << isValidesymbol(str) << endl;
    cout << "str: " << str << endl;
    return 0;
}

