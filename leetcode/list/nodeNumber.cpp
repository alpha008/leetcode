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
xx.求单链表中节点的个数
**********************************************************************************************************/
uint64_t NodeOfList(ListNode * pHead) 
{ 
    unsigned int nLength = 0; 
    ListNode * pCurrent = pHead; 
    if(pHead == NULL) 
        return 0; 

    while(pCurrent != NULL) 
    { 
        nLength++; 
        pCurrent = pCurrent->next; 
    } 
    return nLength; 
}
int main()
{

    vector<int> numsA = {2,4,3};
    vector<int> numsB = {5,6,4};
    ListNode *phead1 = new ListNode(-1);
    ListNode *phead2 = new ListNode(-1);
    createlist(phead1,numsA);
    createlist(phead2,numsB);
    //创建链表并打印
    //2. 链表求和：  从后往前加
    printlist(phead1);
    printlist(phead2);

    cout << "number of  list list1  is :" <<  NodeOfList(phead1) << endl;
    return 0;
}

