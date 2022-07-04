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

/**********************************************************************************************************
141. 判断单链表是否存在环
题目描述：输入一个单向链表，判断链表是否有环。
分析：通过两个指针，分别从链表的头节点出发，
一个每次向后移动一步，另一个移动两步，两个指针移动速度不一样，如果存在环，那么两个指针一定会在环里相遇。
**********************************************************************************************************/
class Solution{
public:
    bool ishashCycle(ListNode*head)
    {
        if(head == nullptr)
            return false;
        ListNode * fast = head ,*slow = head;
        while (fast != nullptr && fast->next !=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};

int main()
{

    vector<int> numsA = {2,3,4,5,6,7,8,9,10};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    // 判断链表是否有环
    printlist(phead1);
    int k  = 3;
    ListNode * p1 = phead1;
    ListNode * p2 = phead1;
    while (p1->next!=nullptr)
    {
        p1 = p1->next;
    }
    
    for(int i = 0; i < k ;i++)
    {
        p2 = p2->next;
    }
    p1->next = p2;
    Solution ab;
    bool result = ab.ishashCycle(phead1);
    cout << "iscyle :" << result << endl;
    return 0;
}

