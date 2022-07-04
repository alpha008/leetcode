#include <iostream>
#include <vector>
#include "list.h"
/**********************************************************************************************************
两个链表求和
You are given two linked lists representing two non-negative numbers.  digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) 
+      (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
**********************************************************************************************************/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        ListNode* cur  = &head;
        int carry = 0;
        for(ListNode* p = l1, * q = l2;
            p != nullptr || q != nullptr;
          p = p == nullptr ? nullptr : p->next, q = q == nullptr ? nullptr : q->next,cur = cur->next)
        {
            int ai = p == nullptr ?  0 : p->val;
            int bi = q == nullptr ?  0 : q->val;
            int val = (ai + bi + carry ) % 10;
            carry = (ai + bi + carry ) / 10;
            cur->next = new ListNode(val);
        }
        if(carry > 0)
           cur->next = new ListNode(carry);  

        return head.next;
    }
};

int main()
{
    //1.创建链表
    std::vector<int> numsA = {2,4,3};
    std::vector<int> numsB = {5,6,4};
    ListNode *phead1 = new ListNode(-1);
    ListNode *phead2 = new ListNode(-1);
    createlist(phead1,numsA);
    createlist(phead2,numsB);

    //2. 链表求和:从后往前加
    printlist(phead1);
    printlist(phead2);
    Solution ab;
    ListNode * addsum = ab.addTwoNumbers(phead1,phead2);
    std::cout << "sum first to last is :" << std::endl;
    printlist(addsum);
    return 0;
}

