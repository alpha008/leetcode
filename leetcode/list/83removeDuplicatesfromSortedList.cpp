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

//17. 删除链表中重复结点  保留一个节点
//1   2   2   3   3  4   4 ---  1234  
class Solution{
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) //当head为空时直接返回NULL，此操作是为了避免循环判断出错。
        return head;
        ListNode* cur = head;
        while(cur->next)  //由于前面判断了head一定不为空，那么直到cur的下一个节点为空时，进行链表遍历。
        {
            if(cur->val == cur->next->val)  //当cur节点的值和下一个节点一致时，将cur下一个节点删除。
            {
                cur->next = cur->next->next;// 如果出现重复，当前cur节点并没有发前移，只是将与其重复的节点删除
            }
            else cur = cur->next; 
        }
        return head;
    }
};


int main()
{
    vector<int> numsA = {2,3,3,4,4,5,5,6,6,7,8,9};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    printlist(phead1);
    Solution ab;
    ListNode * del = ab.deleteDuplicates(phead1);
    cout << "del  result is :" << endl;
    printlist(del);

    return 0;
}

