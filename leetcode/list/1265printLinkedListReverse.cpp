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
7.从尾到头打印单链表
对于这种颠倒顺序的问题，我们应该就会想到栈，后进先出。所以，这一题要么自己使用栈，要么让系统使用栈，也就是递归
**********************************************************************************************************/
void RPrintList(ListNode * pHead) 
{ 
    std::stack<ListNode *> s; 
    ListNode * pNode = pHead; 
    while(pNode != NULL) 
    { 
        s.push(pNode); 
        pNode = pNode->next; 
    } 
    while(!s.empty()) 
    { 
        pNode = s.top(); 
        printf("%d\t", pNode->val); 
        s.pop(); 
    } 
}
int main()
{
    vector<int> numsB = {5,6,4};
    ListNode *phead2 = new ListNode(-1);
    createlist(phead2,numsB);
    printlist(phead2);  
    cout << "RPrintList is "  << endl;
    RPrintList(phead2);
    cout << endl;
    return 0;
}

