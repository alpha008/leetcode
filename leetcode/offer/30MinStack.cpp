#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk_min;
    stack<int> stk;

    MinStack() {

    }
    
    void push(int x) {
        stk.push(x);
        if(stk_min.empty() || x <= stk_min.top())
            stk_min.push(x);
    }
    
    void pop() {
        if(stk.top() == stk_min.top())
            stk_min.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return stk_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}