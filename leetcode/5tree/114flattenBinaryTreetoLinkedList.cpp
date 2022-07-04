#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include "tree.h"
using namespace std;
/*********************************************************************************************************
给你二叉树的根结点 root ，请你将它展开为一个单链表：
展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
         1 
   2           5
3     4   NA     6
------------------------
1
  2
    3
      4
        5
          6 
示例 1：
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/
**********************************************************************************************************/
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> res;
        preTraver(root, res);
        int n = res.size();
        for (int i = 1; i < n; i++) {
            TreeNode *prev = res.at(i - 1), *curr = res.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

    void preTraver(TreeNode* root, vector<TreeNode*> &res) {
        if (root != NULL) {
            res.push_back(root);
            preTraver(root->left, res);
            preTraver(root->right, res);
        }
    }
};


int main()
{
    vector<int> vecTreeNode1 = {1,2,3};
    TreeNode *root1 = createTree(vecTreeNode1);
    vector<vector<int> >result1 = levelOrder33(root1);
    printMatrix(result1);
    return 0;
}




