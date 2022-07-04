#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include "tree.h"
using namespace std;
/***************************************************************************************
二叉树的层序遍历，下面这个方法比较通俗易懂
二叉树：[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
****************************************************************************************/
vector<vector<int> > levelOrder(TreeNode *root)
{
    vector<vector<int> > result;
    if(!root)
        return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int cursize = q.size(); //当前层的节点数量
        vector<int> vec;
        for(int i = 0; i < cursize; i++) 
        {
            auto node = q.front();
            vec.push_back(node->val); // 存储当前层的节点
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(vec);
    }
    //reverse(result.begin(),result.end());
    return result;
}

int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    vector<vector<int> >res = levelOrder(root);
    printMatrix(res);
    return 0;
}