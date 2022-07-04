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

/*82. 删除排序链表中的重复元素 II
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
dummy  1    2     3     3     4      4     5
  cur  
      cur
           cur    d
           cur          d     
           cur               d      
           cur                       d  
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {  // 单次判断两个节点
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;    // 此过程只是改变指针指向
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;  // 此时cur才开始移动
            }
        }
        return dummy->next;
    }
};


int main()
{


    return 0;
}
