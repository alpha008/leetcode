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
/*************************************************************************************************************************
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
示例 3：
输入：head = [1,2,3,4,5], k = 1
输出：[1,2,3,4,5]
示例 4：
输入：head = [1], k = 1
输出：[1]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/wu-bi-xiang-xi-de-zhu-shi-dai-ma-fen-bu-10ud9/
************************************************************************************************************************/
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k < 2)
            return head;
        ListNode *next_group = head;
        for (int i = 0; i < k; ++i) {
            if (next_group)
                next_group = next_group->next;
            else
                return head;
        }
        // next_group is the head of next group
        // new_next_group is the new head of next group after reversion
        ListNode *new_next_group = reverseKGroup(next_group, k);
        ListNode *prev = NULL, *cur = head;
        while (cur != next_group) {
            ListNode *next = cur->next;
            cur->next = prev ? prev : new_next_group;
            prev = cur;
            cur = next;
        }
        return prev; // prev will be the new head of this group
    }
};
// LeetCode, Reverse Nodes in k-Group
// 迭代版，时间复杂度 O(n)，空间复杂度 O(1)
class Solution1 {
public:
//dummy   1    2    3    4    5    6   7   8   // 3个一组
//prev             end
//prev  prev       end
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k < 2) 
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        for(ListNode *prev = &dummy, *end = head; end; end = prev->next) {
            for (int i = 1; i < k && end; i++)
                end = end->next;
            if (end == nullptr) break; // 不足 k 个
            prev = reverse(prev, prev->next, end);
        }
        return dummy.next;
    }
    // prev 是 first 前一个元素, [begin, end] 闭区间，保证三者都不为 null
    // 返回反转后的倒数第 1 个元素
//dummy   1     2    3       4        5    6   7   8   // 3个一组
//prev              end
//prev  begin       end   end_next
//        p    cur  next
//             p    cur   next
//                  p     cur       xx  已经不重要了
// 区间内链表反转
    ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
        ListNode *end_next = end->next;
        for (ListNode *p = begin, *cur = p->next, *next = cur->next;
            cur != end_next;
            p = cur, cur = next, next = next ? next->next : nullptr) 
        {
            cur->next = p;
        }
        begin->next = end_next;  // 区间两个端点
        prev->next = end;
        return begin; // 返回的翻转后的头结点
    }
};
int main()
{
    vector<int> numsA = {1,2,3,4,5,6,7,8,9};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    printlist(phead1);
    Solution ab;
    ab.reverseKGroup(phead1, 3);
    cout << "reverseKGroup result is :" << endl;


    return 0;
}

