#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include "helpvector.h"
using namespace std;
/*******************************************************************************************************
给定一个 普通二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
示例：
    1        |           1          -> null
2     3     |     2    ->    3     -> null
4  5  6   7   | 4  ->  5 ->  6 -> 7  -> null
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，
如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
此题目给的是非完全二叉树
*******************************************************************************************************/
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

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == NULL)
            return root;
        q.push(root);
        while(!q.empty())
        {
            int cursize = q.size();
            Node *prev ;
            Node *node;
            for(int i = 0 ; i < cursize; i ++)
            {
                if( i == 0)
                {
                    prev = q.front();
                    q.pop();
                    node = prev;
                }else{
                    node = q.front();
                    q.pop();
                    prev->next = node;
                    prev = prev->next;
                }
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            prev->next = NULL;  //尾结点
        }
        return root;
    }
};
int main()
{
    return 0;
}



