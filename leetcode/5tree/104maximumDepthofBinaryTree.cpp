#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include "tree.h"
using namespace std;
/********************************************************************************
层序遍历计算二叉树深度
给定一个二叉树，找出其最大深度。借助于层序遍历，然后计算层
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
示例：
给定二叉树 [3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
**********************************************************************************/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root == nullptr) return depth;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int cur = q.size();
            depth ++;       //记录深度，最后返回
            for(int i = 0 ; i < cur; i++)
            {
                auto node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
        }
        return depth;
    }
};

int main()
{
    vector<int> vecTreeNode1 = {1,2,3};
    TreeNode *root = createTree(vecTreeNode1);
    vector<vector<int> >result1 = levelOrder33(root);
    printMatrix(result1);
    Solution ab;

    int res = ab.maxDepth(root);
    cout << "res:" << res << endl;
    return 0;
}