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
/*203. Remove Linked List Elements
删除链表中某一元素
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1); // 借助虚拟节点
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur && cur->next)
        {
            if(cur->next->val == val)        // 找到了节点
            {
                cur->next = cur->next->next;  // cur指针并没有移动
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
int main()
{
    vector<int> numsA = {2,4,3};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    printlist(phead1);
    int k =3;
    Solution ab;
    ListNode * result = ab.removeElements(phead1, k);
    cout << "removeElemen " << k  << endl;
    printlist(result);

    return 0;
}

