#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<limits>
#include<stack>
#include "list.h"
using namespace std;

//445. Add Two Numbers II 
/****************************************************
Input: (7 -> 2 -> 4 -> 3) +
            (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
从后往前加
*****************************************************/
class Solution{
public:
    ListNode *addTwoNumbers(ListNode *p1 ,ListNode *p2)
    {
        if (!p1)
            return p2;
        if(!p2)
            return p1;
        stack<int> s1, s2;
        while (p1 )
        {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2 )
        {
            s2.push(p2->val);
            p2 = p2->next;
        }
        int sum = 0;
        ListNode *tail = new ListNode(0); //尾节点
        while (!s1.empty() || !s2.empty())
        {
            if(!s1.empty()) {sum += s1.top(); s1.pop();}
            if(!s2.empty()) {sum += s2.top(); s2.pop();}
            tail->val = sum %10;   //尾节点存储 余数
            ListNode *prev = new ListNode(sum / 10); //头节点 计算进位
            prev->next = tail;
            tail = prev;       // 尾插法，往开始位置插入
            sum = sum /10;
        }
        return tail->val == 0 ? tail->next : tail; // 如果没有进位 ，如果有进位，tail节点要返回  
    }
};
//               tail 
//       prev -> tail
//prev   tail 
//tail 
int main()
{

    vector<int> numsA = {2,4,3};
    vector<int> numsB = {5,6,4};
    ListNode *phead1 = new ListNode(-1);
    ListNode *phead2 = new ListNode(-1);
    createlist(phead1,numsA);
    createlist(phead2,numsB);
    printlist(phead1);
    printlist(phead2);
    Solution ab;
    ListNode * addsum = ab.addTwoNumbers(phead1,phead2);
    cout << "sum first to last is :" << endl;
    printlist(addsum);

    return 0;
}

