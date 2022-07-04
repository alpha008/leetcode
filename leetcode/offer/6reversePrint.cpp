#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
示例 1：
输入：head = [1,3,2]
输出：[2,3,1]
*/
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode * p = head;
        stack<int> sk;
        if(head == NULL)  return res;
        while(p){
            sk.push(p->val);
            p = p->next;
        }
        while(!sk.empty()){
            res.push_back(sk.top());
            sk.pop();
        }
        return res;
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