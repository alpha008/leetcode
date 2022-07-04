#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include "tree.h"
using namespace std;
/**********************************************************************************************************
遍历查找二叉树中的路径和，判断是否存在
递归在向下计算时，挨个计算每个子问题，然后在搜集问题时，对每个子问题进行叠加计算
示例 2：
  1
2   3
输入：root = [1,2,3], targetSum = 3
输出：true
**********************************************************************************************************/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> result;
        vector<int> cur;
        if( !root ) 
            return result;
        pathSum(root, targetSum, cur, result);
        return result;
    }
    void pathSum(TreeNode*root, int targetSum, vector<int> &cur , vector<vector<int>> &result)
    {
        if(!root) return;
        cur.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == root->val){
                result.push_back(cur);
            }
        }
        pathSum(root->left,  targetSum - root->val , cur, result);
        pathSum(root->right, targetSum - root->val , cur, result);
        cur.pop_back();   // 这里就典型的用到了回溯  结果加入中间状态 要将这个状态消除掉
    }  // 这里是回溯的经典用法，此题必须掌握
};

int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    vector<vector<int> >result = levelOrder33(root);
    printMatrix(result);
    Solution ab;
    vector<vector<int> > res = ab.pathSum(root,15);
    printMatrix(res);
    return 0;
}


