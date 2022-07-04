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

//147. Insertion Sort List  //插入法排序将链表排序
//         1 --- 4 --- 5 --- 3 --- 2
//dummy   head   
//pre           cur
//        
class Solution{
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        if (head == nullptr)
            return head;
        ListNode *dummy = new ListNode(-1); // 创建一个新的链表头节点
        while(head != nullptr)
        {
            ListNode *pre = dummy;      // 每次都从头开始
            ListNode *cur = head->next; // cur 从第二个节点开始移动
            while(pre->next != nullptr && pre->next->val < head->val) //比的是头节点
            {
                pre = pre->next;        // 比的是prev的next节点，当找到第一个不大于当前节点时，prev节点为将要插入的节点
            }
            head->next = pre->next;
            pre->next = head;           // 插入到已经排序的新链表中
            head = cur;                 // head始终是未排序的首节点
        }
        return dummy->next;
    }
};


int main()
{
    vector<int> numsA = {2,4,3,8,7,5,3,1};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    printlist(phead1);
    Solution ab;
    ListNode * insertsort = ab.insertionSortList(phead1);
    cout << "insertsort result is :" << endl;
    printlist(insertsort);

    return 0;
}

