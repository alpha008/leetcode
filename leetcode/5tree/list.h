#include<iostream>
#include<vector>
using namespace std;
class ListNode{
    public:
    ListNode(int x){
        this->val = x;
        this->next = NULL;
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    int val;
    ListNode *next;
};
#if 0
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
#endif
/*************************************************************************************************
 根据数组创建链表，头结点的数据域一般不使用
 *************************************************************************************************/
void createlist(ListNode *phead,vector<int> nums)
{
    ListNode *ptemp = phead; //指向头结点
    ptemp->val = nums[0]; //头结点是否存储数据
    for(int i = 1; i < nums.size();i++){
        ListNode *pnewNode = new ListNode(-1);
        pnewNode->val = nums[i];
        ptemp->next = pnewNode;
        pnewNode->next = nullptr;
        ptemp = pnewNode;
    }
}
/*************************************************************************************************
添加节点，添加到尾部，需要遍历链表
 *************************************************************************************************/
void addNode(ListNode *phead,int value)
{
    ListNode * ptmp = phead;
    ListNode *pNewNode = new ListNode(value);
    if(phead == NULL)
        phead = pNewNode;
    else
    {
        while(ptmp->next != NULL) {
            ptmp = ptmp->next;
        }
        ptmp->next = pNewNode;
    }
}
/*************************************************************************************************
删除节点时，需要记录上个节点的信息
 *************************************************************************************************/
void delNode(ListNode *phead,int value)
{
    if(phead == NULL) 
        return ;
    ListNode * prev;
    ListNode * pcur = phead;
    while(pcur->val != value)
    {
        prev = pcur;//记录要删除结点的上一个结点
        pcur = pcur->next ;
    }
    prev -> next = pcur->next; 
}

/*************************************************************************************************
 遍历链表
 *************************************************************************************************/
void printlist(ListNode *phead)
{
    ListNode *ptemp = phead;
    if(phead == nullptr)
        return ;

    while(ptemp)
    {
        cout << "val-> = "<< ptemp->val << "; " ;
        ptemp = ptemp ->next;
    }
    cout << endl;
}