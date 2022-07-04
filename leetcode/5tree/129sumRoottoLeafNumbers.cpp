#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include "tree.h"
using namespace std;
/*******************************************************************************************
给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：
例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。
叶节点 是指没有子节点的节点。
   1
2     3
示例 1：
输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/solution/qiu-gen-dao-xie-zi-jie-dian-shu-zi-zhi-he-by-leetc/
/*******************************************************************************************/
//深度优先搜索
class Solution {
public:
    int dfs(TreeNode* root, int sum )   // 这个题目跟求路径和很相似  判断存在与否 求出具体路径
    {
        if(!root) 
            return 0;
        if(root->left == NULL && root->right == NULL)
            return sum * 10 + root->val;             
        return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);    
    }
    int sumNumbers(TreeNode* root)
    {
        int result = dfs(root, 0);
        return result;    
    }
};
//广度优先搜索
class Solution1 {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> nodeQueue;
        queue<int> numQueue;
        nodeQueue.push(root);
        numQueue.push(root->val);  // 记录以当前节点结尾的 路径和
        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();  // 层序遍历，头节点，每层节点
            int num = numQueue.front(); // 以当前节点结尾的和
            nodeQueue.pop();
            numQueue.pop(); 
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if (left == nullptr && right == nullptr) {
                sum += num;  // 如果是叶子结点，那么求和
            } else {
                if (left != nullptr) {  
                    nodeQueue.push(left);
                    numQueue.push(num * 10 + left->val);  // 如果不是叶子结点，那么继续*10 + val入队列
                }
                if (right != nullptr) {
                    nodeQueue.push(right);
                    numQueue.push(num * 10 + right->val); // 如果不是叶子结点，那么继续*10 + val入队列
                }
            }
        }
        return sum;  // 返回所有路径之和
    }
};
int main()
{
    return 0;
}