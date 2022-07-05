#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include<algorithm>
#include "tree.h"
using namespace std;
/********************************************************************************
637. 二叉树的层平均值
          1
    2          3
 4    5     6       7
8 9 10 11 12  13  14  15 
**********************************************************************************/
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            double sum = 0;
            int cursize = q.size();
            for(int i = 0; i  < cursize; i ++)
            {
                auto node = q.front();
                q.pop();
                sum = sum + node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(sum / cursize);
        }
        return res;
        
    }
};

int main()
{
    vector<int> vecTreeNode1 = {1,2,3,4,5,6,7};
    TreeNode *root = createTree(vecTreeNode1);
    vector<vector<int> >result1 = levelOrder33(root);
    printMatrix(result1);
    Solution ab;
    vector<double> res = ab.averageOfLevels(root);
    return 0;
}



