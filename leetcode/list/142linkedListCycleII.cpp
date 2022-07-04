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
142. 找到环的入口点
题目描述：输入一个单向链表，判断链表是否有环。如果链表存在环，如何找到环的入口点？
解题思路：由上题可知，按照 p2 每次两步，p1 每次一步的方式走，发现 p2 和p1 重合，确定了单向链表有环路了。
接下来，让p2回到链表的头部，重新走，每次步长不是走2了，而是走1，那么当 p1 和 p2 再次相遇的时候，就是环路的入口了。。
**********************************************************************************************************/
class Solution{
public:
    ListNode* detectCycle(ListNode *head)
    {
        //如果head为空，或者为单结点，则不存在环
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow,*fast;
        slow = fast = head;
        //先判断是否存在环
        while(fast != NULL &&  fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        if(fast != slow)  
            return NULL;            //不存在环直接返回
        fast = head;                //快指针从头开始走
        while(fast !=  slow)            //两者相遇即为入口点
        {
            fast = fast->next;	//快指针现在步长变为1
            slow = slow->next;	//慢指针还是继续行走
        }
        return fast;	//这个点就是入口点其实返回 slow 效果也是一样的
    }
};

int main()
{

    ListNode *pnode1 = new ListNode(1);
    ListNode *pnode2 = new ListNode(2);
    ListNode *pnode3 = new ListNode(3);
    ListNode *pnode4 = new ListNode(4);
    ListNode *pnode5 = new ListNode(5);
    ListNode *pnode6 = new ListNode(6);
    ListNode *pnode7 = new ListNode(7);
    pnode1->next = pnode2;
    pnode2->next = pnode3;
    pnode3->next = pnode4;
    pnode4->next = pnode5;
    pnode5->next = pnode6;
    pnode6->next = pnode7;
    pnode7->next = pnode5;
    Solution ab;
    ListNode *node = ab.detectCycle(pnode1);
    cout << "iscyle :" << node->val << endl;

    return 0;
}

