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
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/dong-hua-yan-shi-kuai-man-zhi-zhen-19-sh-n9ih/
// 删除倒数第k个结点   1 2 3 4 5 6 7
/*  n = 3
    1  2  3  4  5  6  7  null
  x 1  2  3  4  5  6  7  null
                3
             f // 往后面走n+1个位置
  s          s  x  x  x  f        f要比s快 n+1 个位置
*****************************************************************************************/
class Soultion{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode dummy{-1, head};
        ListNode *s = &dummy, *f = &dummy;
        for (int i = 0; i < n; i++) // q先走n步
        {
            if(!f) return nullptr;
            f = f->next; 
        }
        while(f->next) {            // ̯一起走
            s = s->next;
            f = f->next;
        }
        ListNode *del = s->next;
        s->next = s->next->next;
        delete del;
        return dummy.next;
    }
};

int main()
{
    vector<int> numsA = {1,2,3,4,5,6,7,8,9};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    // 创建链表并打印
    printlist(phead1);
    // 删除倒数第k个节点
    int k = 9;
    Soultion ab;
    ListNode * NowHead = ab.removeNthFromEnd(phead1,k);
    cout << "del " << k <<  " list result is " << endl;
    printlist(NowHead);

    return 0;
}

