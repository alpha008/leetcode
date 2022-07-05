#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<limits.h>
#include<algorithm>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/**********************************************************************************************
530. 二叉搜索树的最小绝对差
验证是否为搜索二叉树
节点的左⼦树只包含⼩于当前节点的数。
节点的右⼦树只包含⼤于当前节点的数。

中序遍历二叉搜索树为递增的，那么前后就可以找出差值最小的数

链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/solution/530-er-cha-sou-suo-shu-de-zui-xiao-jue-dui-chai-yo/
***********************************************************************************************/
class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val); // 将二叉搜索树转换为有序数组
        traversal(root->right);   // 中序遍历，二叉树为顺序递增关系
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        traversal(root);
        if (vec.size() < 2) return 0;
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); i++) { // 统计有序数组的最小差值
            result = min(result, vec[i] - vec[i-1]);
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