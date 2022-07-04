#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <limits.h>
#include "tree.h"
using namespace std;
/******************************************************************************************
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。
该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。
示例 1：
    1
2      3
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
    a
   / \
  b   c
b + a + c。
b + a + a 的父结点。
a + c + a 的父结点。

链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/
*******************************************************************************************/
class Solution {
public:
    int max_sum = INT_MIN;
    //后序遍历树，返回经过root的单边最大路径和，并维护整棵树的最大路径和
    int dfs(TreeNode* node)
    {
        //终止条件
        if (node == nullptr) return 0;
        //深度优先，获取左右分支的最大路径和，本结点作为联络点
        //若左右分支返回的值为负数，则对路径和做负贡献，直接舍弃
        int left_max  = max(0, dfs(node->left));
        int right_max = max(0, dfs(node->right));
        //由于路径最大的一种可能为left->node->right，而不向root的父结点延伸
        int lnr_sum = left_max + node->val + right_max;   //   b --> a --> c
        //更新最大值，全是负数结点的情况，也会在这里更新最大的负数
        max_sum = max(max_sum, lnr_sum);   //  
        //向node的父结点返回经过node的单边分支的最大路径和 .   返回单边最大值
        int ret = node->val + max(left_max, right_max);
        return ret;
    }
    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        return max_sum;
    }
};

//https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/java-zhuan-ti-jiang-jie-di-gui-si-lu-qin-qx8a/
class Solution1{
public:
    int maxRes = INT_MIN;
    int maxPathSum(TreeNode* root)
    {
        postOrder(root);
        return maxRes;
    }
    int postOrder(TreeNode* root)
    {
        if(root == nullptr)
            return 0 ;
        int left = max(postOrder(root->left),0);
        int right = max(postOrder(root->right),0);
        maxRes = max(maxRes, root->val + left + right);  //  记录中间状态的最大值   b a c
        //记录中间状态  此处记录的是不包含当前节点的父亲节点的路径最大和 中间状态产生最大值
        return root->val + max(left, right);  // 包含当前节点的左边或者右边最大值
        // 往上层返回，只能返回单边   
    }
};
int main()
{
    vector<int> vecTreeNode1 = {1,2,3};
    TreeNode *root1 = createTree(vecTreeNode1);
    vector<vector<int> >result1 = levelOrder33(root1);
    printMatrix(result1);

    return 0;
}