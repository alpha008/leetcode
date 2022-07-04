#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/**********************************************************************************************
验证是否为二叉搜索树
节点的左⼦树只包含⼩于当前节点的数。
节点的右⼦树只包含⼤于当前节点的数。
所有左⼦树和右⼦树⾃身必须也是⼆叉搜索树
***********************************************************************************************/
class Solution{
public:
    vector<int>vec;
    void travel(TreeNode*root)
    {   
        if(root == nullptr) return;
        travel(root->left);
        vec.push_back(root->val);
        travel(root->right);

    }
    bool isValidBST(TreeNode* root)
    {
        vec.clear();
        travel(root);   // 利用中序遍历，然后判断是否递增
        for(int i = 1; i < vec.size(); i++)
        {
            if(vec[i] <= vec[i-1])  return false;
        }
        return true;
    }
};
/************************************************************************************************************
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*************************************************************************************************************/
class Solution1 {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    return 0;
}