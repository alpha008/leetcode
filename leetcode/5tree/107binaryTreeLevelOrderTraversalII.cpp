#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include "tree.h"
using namespace std;
/**********************************************************************************************************
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层序遍历为：
[
  [15,7],
  [9,20],
  [3]
]
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
**********************************************************************************************************/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int> >res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int cursize = q.size();
            res.push_back(vector<int>());   // 这个写法不错
            for (int i = 0 ; i < cursize; i ++) 
            {
                auto node = q.front();
                q.pop();            //左右子树不为空就加入队列
                res.back().push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    Solution ab;
    vector<vector<int> >res = ab.levelOrderBottom(root);
    printMatrix(res);
    return 0;
}