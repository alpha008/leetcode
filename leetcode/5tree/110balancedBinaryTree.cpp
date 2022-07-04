#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include "tree.h"
using namespace std;

/************************************************************************************
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
       3
    9    20
      15    7
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree


这道题中的平衡二叉树的定义是：二叉树的每个节点的左右子树的高度差的绝对值不超过 1，
则二叉树是平衡二叉树。根据定义，一棵二叉树是平衡二叉树，当且仅当其所有子树也都是平衡二叉树，因此可以使用递归的方式判断二叉树是不是平衡二叉树
递归的顺序可以是自顶向下或者自底向上。
*************************************************************************************/
class Solution {
public:
    int height(TreeNode* root) {  // 递归求二叉树的高度
        if (root == NULL) {
            return 0;
        } else {
            return max(height(root->left), height(root->right)) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return abs(height(root->left) - height(root->right)) <= 1 && 
                isBalanced(root->left) && isBalanced(root->right);
        }
    }
};

int main()
{

    return 0;
}



