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
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) 
        return NULL;
        //1. 正常遍历，将拷贝后的节点插入到新链表后面
        for (Node* cur = head; cur != NULL; ) {
            Node* node = new Node(cur->val); // 拷贝头节点
            node->next = cur->next;          // 将拷贝的节点的下一个节点指向头节点
            cur->next = node;                // 当前节点指向新的节点
            cur = node->next;                // 将当前节点移动到新创建的节点后面
        }
        //2.A的指针指向的就是Arandom指针指向的下一个节点即 A'.random = A.random.next =C'
        // https://blog.csdn.net/dpengwang/article/details/85270664
        for (Node* cur = head; cur != NULL; ) {
            if (cur->random != NULL)
                cur->next->random = cur->random->next; // 要指向新插入的结点，在随机结点的后面一个是新创建的节点
            cur = cur->next->next;// 遍历新拷贝的节点
        }
        // 分拆两个单链表  新建一个头节点，连接起来即可
        Node new_head(-1);
        for (Node* cur = head, *new_cur = &new_head; cur != NULL; ) {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return new_head.next;
    }
};

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
    /*ListNode * addsum = copyRandomList(phead1);*/
    cout << "reverse list result is :" << endl;
    //printlist(addsum);

    return 0;
}

