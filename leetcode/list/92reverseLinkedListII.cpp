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
//92. Reverse Linked List II   // 将m -n 之间的结点翻转
/*
输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
*/ 
class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head == nullptr ) 
            return head;
        ListNode  dummy(-1);
        dummy.next = head;  // 记录链表头节点，并返回头节点
        ListNode * prev_m ,*prev = &dummy;
        int len = 1;
        ListNode *count = head;
        while (count != nullptr)
        {
            count = count->next;
            len++;
        }
        if(right > len)                 // 当节点数不够时
            return head;                // 将 m -n 之间的节点逆序 ，需要找到第m-1个节点，然后将最后一个节点依次插入到m-1节点的后面

        for(int i = 1; i <= right; i++) 
        {
    //         x      2       x        4      x     x     x    x
    //dummy    1      2       3        4      5     6     7    8   // 找到目标节点，然后将后面节点挨个插入哨兵节点的后面
    //prev    head      
    //        prev   head
    //       prev_m  prev    head
    //dummy    1      3       2        4      5     6     7    8   // 找到目标节点，然后将后面节点挨个插入哨兵节点的后面
    //                       prev     head  
            if(i == left )
                prev_m = prev;              // 第m个节点的前面一个节点的位置
            if(i > left && i <= right){ 
                prev->next = head->next;    // 2->4  先把要插入的结点移除原链表
                head->next = prev_m->next;  // 3->2  插入到m结点后面第一个节点的前面
                prev_m->next = head;        // 1->3  m结点指向插入的结点
                head = prev;                // 前面的结点由于翻转变成了头结点
            }
            prev = head;
            head = head->next;
        }
        return dummy.next;    //返回头节点
    }
};

int main()
{
    vector<int> numsA = {2,3,4,5,6,7,8,9,10};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    printlist(phead1);
    Solution ab;
    ListNode * reverse  = ab.reverseBetween(phead1, 3, 4);
    cout << "reverse list result is :" << endl;
    printlist(reverse);

    return 0;
}