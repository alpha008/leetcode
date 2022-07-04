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
23.合并k个有序链表，并返回头指针   考查链表连接
**********************************************************************************************************/
class Solution {
public:
    ListNode *mergeTwoLists(ListNode*l1 , ListNode *l2){
        ListNode dummy(-1);
        for(ListNode * p = &dummy;l1 != nullptr || l2 != nullptr;p = p->next){  // 新链表开始游走
            int val1 = l1 == nullptr ? INT32_MAX : l1->val;
            int val2 = l2 == nullptr ? INT32_MAX : l2->val;
            if(val1 <= val2){    //较小的链表存储起来，然后指向这个元素
                p->next = l1; 
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        return dummy.next;
    }

    ListNode *mergeKLists(vector<ListNode *>&Lists){
        if(Lists.size() == 0 ) 
            return nullptr;
        ListNode * p = Lists[0];
        for(std::size_t i = 1;i < Lists.size(); i++){
            p = mergeTwoLists(p, Lists[i]);
        }
        return p ;
    }
};


int main()
{

    vector<int> numsA = {1,2,3};
    vector<int> numsB = {4,5,6};
    vector<int> numsC = {7,8,9};
    ListNode *phead1 = new ListNode(-1);
    ListNode *phead2 = new ListNode(-1);
    ListNode *phead3 = new ListNode(-1);
    createlist(phead1,numsA);
    createlist(phead2,numsB);
    createlist(phead3,numsC);
 
    //2. 合并k个有序链表
    printlist(phead1);
    printlist(phead2);
    printlist(phead3);
    vector<ListNode*> result;
    result.push_back(phead1);
    result.push_back(phead2);
    result.push_back(phead3);
    Solution ab;
    ListNode * mergeResult =ab.mergeKLists(result);
    cout << "mergeResult is :" << endl;
    printlist(mergeResult);

    return 0;
}

