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
class Solution{
public:
    /**********************************************************************************************************
    查找单链表的中间结点
    获取单链表中间结点，若链表长度为 n(n>0) ， 则返回第 n/2+1 个结点 
    **********************************************************************************************************/
    ListNode * GetMiddleNode(ListNode * pHead) 
    { 
        if(pHead == NULL || pHead->next == NULL) // 链表为空或只有一个结点，返回头指针 
            return pHead; 
    
        ListNode * pfast = pHead; 
        ListNode * pslow = pHead; 
        while(pfast->next != NULL) // 前面指针每次走两步，直到指向最后一个结点，后面指针每次走一步 
        {
            pfast = pfast->next; 
            pslow = pslow->next; 
            if(pfast->next != NULL)  //pfast 该指针一个循环走两次
                pfast = pfast->next; 
        } 
        return pslow; // 后面的指针所指结点即为中间结点 
    }
};

int main()
{

    vector<int> numsA = {1,2,3,4,5,6,7,8,9,10};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    printlist(phead1);
    Solution ab;
    ListNode * midNode = ab.GetMiddleNode(phead1);
    cout << "mid list node is " << midNode->val << endl;

    return 0;
}

