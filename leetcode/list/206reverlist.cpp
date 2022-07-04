#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits>
#include<stack>
#include "list.h"
using namespace std;

/**********************************************************************************************************
反转链表
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
示例:
输入:        1->2->3->4->5->NULL
输出:  NULL<-1<-2<-3<-4<-5
             1       2     3    4   5 
     revhead
            prev    cur 
**********************************************************************************************************/
class Solution{
public:
    ListNode* reverseList(ListNode* head) 
    {  
        if(head == NULL || head->next == NULL)// 如果链表为空或只有一个结点，无需反转，直接返回原链表头指针 
            return head; 
        ListNode * rhead = NULL;     // 反转后的新链表头指针，初始为NULL 
        ListNode * cur = head; 
        while(cur != NULL) 
        { 
            ListNode * prev = cur; 
            cur = cur->next; 
            prev->next = rhead; // 将当前结点摘下，插入新链表的最前端 
            rhead = prev; 
        } 
        return rhead; 
    }
};

int main()
{
    vector<int> numsA = {2,4,3};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    // 翻转一个链表
    printlist(phead1);
    Solution ab;
    ListNode * result = ab.reverseList(phead1);
    cout << "reverse list result is :" << endl;
    printlist(result);
    return 0;
}

