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
160. 判断两个单链表是否相交
如果两个链表相交于某一节点，那么在这个相交节点之后的所有节点都是两个链表所共有的。也就是说，
如果两个链表相交，那么最后一个节点肯定是共有的。先遍历第一个链表，记住最后一个节点，然后遍历第二个链表，
到最后一个节点时和第一个链表的最后一个节点做比较，如果相同，则相交，否则不相交。
时间复杂度为O(len1+len2)，因为只需要一个额外指针保存最后一个节点地址，空间复杂度为O(1)。
**********************************************************************************************************/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return  NULL;
        int len1 = 1;
        ListNode* p1 = headA;
        while(p1->next!=NULL)
        {
            len1++;
            p1 = p1->next;
        }
        ListNode* p2 = headB;
        int len2 = 1;
        while(p2->next!= NULL)
        {   
            len2++;
            p2 = p2->next;
        }
        if(p1 != p2) return NULL;    // 走到最后一个节点肯定会是相同的节点
        ListNode *node1  = headA;
        ListNode *node2  = headB;
   
        if(len1 > len2)
        {
            int k = len1 - len2;
            while(k--)
            {
                node1 = node1->next;
            }
        }else{
            int k = len2 - len1;
            while(k--)
            {
                node2 = node2->next;
            }
        }
        while(node1 !=node2)   // 长链表先走k步，然后同时走，相遇即为交点
        {
            node1 = node1->next;
            node2 = node2->next;      
        }   
        return node1;
    }
};
int main()
{

    vector<int> numsA = {2,4,3};
    vector<int> numsB = {5,6,4};
    ListNode *phead1 = new ListNode(-1);
    ListNode *phead2 = new ListNode(-1);
    createlist(phead1, numsA);
    createlist(phead2, numsB);
    // 判断两个单链表是否相交
    printlist(phead1);
    printlist(phead2);
    Solution ab;
    bool IsSection = ab.getIntersectionNode(phead1,phead2);
    cout << "IsSection  is :" << IsSection << endl;
    return 0;
}

