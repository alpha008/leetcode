#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //定义虚拟头结点
        ListNode *res = new ListNode(0), *p = res;
        while(l1 && l2 ){
            l1->val < l2->val ? (p->next = l1,l1 = l1->next) : (p->next = l2, l2 = l2->next);
            p = p->next;              
        }
        //因为l1 l2长度可能不一样 所以跳出循环的时候p->next为不为空的那个
        p->next = l1 ? l1 : l2;
        return res->next;
    }
};
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}