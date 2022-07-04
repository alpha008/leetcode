
#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/************************************************************************************
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
示例1：
输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
解释:
          1
         / \
        3   2
       / \   \  
      5   3   9 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
根据层序遍历找出每层的最大值
*************************************************************************************/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int max = INT32_MIN;
            int cursize = q.size();
            for(int i = 0; i < cursize; i++)
            {
                auto node = q.front();
                q.pop();
                if(node->val > max) max = node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            res.push_back(max);
        }
        return res;
    }
};

int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    vector<vector<int> >result1 = levelOrder33(root);
    printMatrix(result1);

    
    return 0;
}