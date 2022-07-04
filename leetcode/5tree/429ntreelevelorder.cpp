#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/**********************************************************************************************
429
输入：root = [1,null,3,2,4,null,5,6]
输出：[[1],[3,2,4],[5,6]]
树的形状如下
       1
    3     2   4
  5   6
层序遍历结果: [[1],[3,2,4],[5,6]]
n叉树的层序遍历
**********************************************************************************************/
class Solution{
public:
    vector<vector<int>> levelOrderN(Node *root)
    {
        queue<Node*> q;
        if(!root)
            q.push(root);
        vector<vector<int>> result;
        while (!q.empty())
        {
            vector<int> vec;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                vec.push_back(node->val);
                for(int i = 0; i < node->children.size(); i ++)
                {
                    if(node->children[i] != nullptr) q.push(node->children[i]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};


int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    
    return 0;
}

