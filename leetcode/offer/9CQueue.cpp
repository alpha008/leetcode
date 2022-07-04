#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
示例 1：
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
用两个栈实现一个队列
*/
class CQueue {
public:
    CQueue() {
    }
    void appendTail(int value) {
        one.push(value);
    }
    
    int deleteHead() {
        if (two.empty()) {
            while(!one.empty()) {
                two.push(one.top());
                one.pop();
            }
        }
        if (two.empty())
            return -1;
        int res = two.top();
        two.pop();
        return res;       
    }
    stack<int> one;
    stack<int> two;
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}