#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include "tree.h"
using namespace std;

/***************************************************************************************
检查是否是镜像二叉树， 是否中心对称
     1              1
  2      2       2      2
3   4  4   3   3   4  4   3
****************************************************************************************/
class Solution {
public:
    //1 递归做法
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }

    //2 迭代做法
    bool check1(TreeNode *u, TreeNode *v) { // 想象成两棵树  
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;  // 到达叶子节点
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left);  // 左子树与右子树比较
            q.push(v->right);
 
            q.push(u->right); // 右子树与左子树比较
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric1(TreeNode* root) {
        return check1(root, root);
    }

};

int main()
{

    return 0;
}