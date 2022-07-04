#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include "tree.h"
using namespace std;
/**************************************************************************************
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。
      3
  9      20
      15    7
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：2
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
求出二叉树的最小深度，求出二叉树的最大深度
均需要一个depth记录层数
*************************************************************************************/
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode *, int> > que;
        que.emplace(root, 1);
        while (!que.empty()) {
            TreeNode *node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;  // 如果为叶子结点，直接返回 结点对应的层 标记位
            }
            if (node->left != nullptr) {
                que.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                que.emplace(node->right, depth + 1);
            }
        }

        return 0;
    }
};


int main()
{
 
    return 0;
}



