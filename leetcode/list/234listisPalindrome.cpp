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
/*********************************************************************************************
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
示例 1：
输入：head = [1,2,2,1]
输出：true
示例 2：
输入：head = [1,2]
输出：false

提示：
链表中节点数目在范围[1, 105] 内  0 <= Node.val <= 9
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*********************************************************************************************/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s;   //用来存储链表中的数据
        while(head != NULL){  //遍历链表
            s += head->val;   //将数据存入链表
            head = head->next;    
        }
        int i = 0;              //头指针
        int j = s.length() - 1; //尾指针
        while(i < j){           //开始遍历
            if(s[i] != s[j]){ //将头对应的尾进行匹配对比，如果不相等直接return false
                return false;;
            }else{
                i++;    //如果本次一对字符匹配成功，那么i指针后移，j指针前移
                j--;
            }
        }
        return true;    //若遍历结束，则说明是回文，直接return true
    }
};


int main()
{
    vector<int> numsA = {2,4,3};
    ListNode *phead1 = new ListNode(-1);
    createlist(phead1,numsA);
    printlist(phead1);
    Solution ab;
    bool flag = ab.isPalindrome(phead1);
    cout << "flag " << flag  << endl;
    return 0;
}

