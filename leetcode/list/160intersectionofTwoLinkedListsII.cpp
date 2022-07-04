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
/*********************************************************************************************************
求相交链表的节点
**********************************************************************************************************/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) 
            return NULL; 
        int len1 = 1; 
        ListNode * pTail1 = headA; 
        while(pTail1->next != NULL) 
        { 
            pTail1 = pTail1->next; 
            len1++; 
        } 
        int len2 = 1; 
        ListNode * pTail2 = headB; 
        while(pTail2->next != NULL) 
        { 
            pTail2 = pTail2->next; 
            len2++; 
        } 
    
        if(pTail1 != pTail2) // 不相交直接返回NULL 
            return NULL; 
    
        ListNode * pNode1 = headA; 
        ListNode * pNode2 = headB; 
        // 先对齐两个链表的当前结点，使之到尾节点的距离相等 
        if(len1 > len2)  // 长的先走
        { 
            int k = len1 - len2; 
            while(k--) 
                pNode1 = pNode1->next; 
        } 
        else
        { 
            int k = len2 - len1; 
            while(k--) 
                pNode2 = pNode2->next; 
        } 
        while(pNode1 != pNode2)  // 两个指针处于同级别的起始位置，然后在同时往下面走，这时就可以了
        { 
            pNode1 = pNode1->next; 
            pNode2 = pNode2->next; 
        } 
        return pNode1; 
    }
};


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
    ListNode * node = ab.getIntersectionNode(phead1, phead2);
    cout << "node  :" << node->val << endl;


    return 0;
}

