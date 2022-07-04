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
/**********************************************************************************************
61. Rotate List
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
Given a linked list, rotate the list to the right by k kk places, where k kk is non-negative.
**********************************************************************************************/
class Solution{
public:
    ListNode *rotateRightTest(ListNode *head, int k)
    {
        if(head == nullptr || k == 0 )
            return head;
        int len = 1;
        ListNode *p = head;
        while(p->next)
        {
            len++;
            p = p->next;
        } // 计算链表长度
        p->next = head;  // 先连接首尾成环
        k = len - k % len;
        for(int step = 0; step < k;step++)
        {
            p = p->next;
        }
        head = p->next;   // 找到尾巴节点 断开即可
        p->next = nullptr;
        return   head;
    }
};
//  1  2  3  4  5  6 
//           p

int main()
{

    vector<int> numsA = {2,3,4,5,6,7,8,9};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    printlist(phead1);
    int k = 3;
    Solution ab;
    ListNode * addsum = ab.rotateRightTest(phead1,k);
    cout << "rotateRightTest is :" << endl;
    printlist(addsum);

    return 0;
}

