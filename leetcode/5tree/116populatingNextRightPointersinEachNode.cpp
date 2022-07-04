#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include "helpvector.h"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
/*******************************************************************************************************
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
示例：
     1        |           1          -> null
  2     3     |     2    ->    3     -> null
4  5  6   7   | 4  ->  5 ->  6 -> 7  -> null
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，
如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
*******************************************************************************************************/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == NULL) return root;
        q.push(root);
        while(!q.empty())
        {
            int cursize = q.size();
            Node* prev = NULL ; // 前驱节点
            Node* cur = NULL ;  // 游标节点
            for(int i = 0; i < cursize ; i++)
            {
                if(i == 0 ){
                    prev = q.front();  //prev 记录当前层 起始节点
                    q.pop();
                    cur  = prev;   //cur节点  作为游标节点
                }else{
                    cur = q.front();
                    q.pop();
                    prev->next = cur;  // 第二层，起始节点指向当前节点，前后连接
                    prev = prev->next;     // prev 节点一起后移
                }
                if(cur->left != NULL) q.push(cur->left);
                if(cur->right != NULL) q.push(cur->right);    
            } // curNode 在移动的过程中，往后遍历
            prev->next = NULL;  // 当该层遍历结束时，指向末尾节点
        }
        return root;
    }
};
int main()
{

    return 0;
}