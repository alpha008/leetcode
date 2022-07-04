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
/******************************************************** 
        1       2        3     
dummy 
prev   cur   next   只是改变next指针
        2       1       3      null
dummy 
prev  next     cur       只是改变next指针

      next     cur
               prev    cur     next 
******************************************************** */
class Soultion{
public:
    //24. Swap Nodes in Pairs
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)  // 需要判断两个节点
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        for(ListNode *prev = &dummy,*cur = prev->next,*next = cur->next;
            next; // 当剩下节点数不够两个时结束
            prev = cur,cur = cur->next, next = cur ? cur->next : NULL)  
        {                                           // 这里判断了第二个节点是否为空             
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }

    // 这种方法并没有改变指针的指向
    ListNode* swapPairs24(ListNode* head) {
        if(head == nullptr || head->next == nullptr)  
            return head;
        ListNode * p = head;
        while(p && p->next)
        {
            swap(p->val, p->next->val);
            p = p->next->next;
        }
        return head;
    }
};


int main()
{
    vector<int> numsA = {1,2,3,4,5,6,7,8,9};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    printlist(phead1);
    Soultion ab;
    ListNode * addsum = ab.swapPairs24(phead1);
    cout << "swapPairs2 result is :" << endl;
    printlist(addsum);

    return 0;
}

