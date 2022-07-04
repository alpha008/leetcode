#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include "list.h"
using namespace std;
/**********************************************************************************************************
合并链表并返回头指针
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
输入：1->2->4 
      1->3->4
输出：1->1->2->3->4->4
**********************************************************************************************************/
ListNode *mergeTwoLists(ListNode*l1 , ListNode *l2){
    ListNode dummy(-1); // 虚拟头节点
    for(ListNode * cur = &dummy;l1 != nullptr || l2 != nullptr;cur = cur->next){
        int val1 = l1 == nullptr ? INT32_MAX : l1->val; 
        int val2 = l2 == nullptr ? INT32_MAX : l2->val;
        if(val1 <= val2){
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
    }
    return dummy.next;
}

int main()
{
    vector<int> numsA = {2,3,4};
    vector<int> numsB = {5,6,7};
    ListNode *phead1 = new ListNode(-1);
    ListNode *phead2 = new ListNode(-1);
    createlist(phead1,numsA);
    createlist(phead2,numsB);
    //21. 按顺序合并两个链表
    printlist(phead1);
    printlist(phead2);
    ListNode * MergeList = mergeTwoLists(phead1,phead2);
    cout << "merge list  is :" << endl;
    printlist(MergeList);

    return 0;
}

