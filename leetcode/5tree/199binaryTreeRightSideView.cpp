#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/*******************************************************************************************
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
示例 1:
            1 
       2        3 
  null   5   null   4
输入: [1,2,3,null,5,null,4]
输出: [1,3,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
二叉树的右视图 -- 右边最后一个节点存储 为右视图
*******************************************************************************************/
class Solution{
public:
    vector<int>  rightSideView(TreeNode *root)
    {
        vector<int> result;
        if(!root)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int cursize = q.size();
            for(int i = 0; i < cursize; i++)
            {
                auto node = q.front();
                if(i == cursize - 1) // 记录最右边一个节点即可
                {
                    result.push_back(node->val);
                }
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return result;
    }
};


int main()
{
    Solution ab;
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    vector<int>res = ab.rightSideView(root);
    vec_print(res);
    return 0;
}

