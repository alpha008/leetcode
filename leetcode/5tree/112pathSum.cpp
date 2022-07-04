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
左右子树均需要递归遍历
**********************************************************************************************************/
class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum){
        if(!root) 
            return false;
        if(root->left == nullptr && root->right == nullptr)   
            return targetSum == root->val;//结束条件，叶子节点   只有到了叶子节点才会去判断结果
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    vector<vector<int> >result = levelOrder33(root);
    printMatrix(result);
    Solution ab;

    bool res = ab.hasPathSum(root,15);
    cout << "res:" << res << endl;
    return 0;
}

