
#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/*****************************************************************
示例：
    3
   / \
  9  20
    /  \
   15   7
在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
链接：https://leetcode-cn.com/problems/sum-of-left-leaves/solution/zuo-xie-zi-zhi-he-by-leetcode-solution/
*****************************************************************/
//深度优先搜索
class Solution {
public:
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int dfs(TreeNode* node) {
        int ans = 0;
        if (node->left) {  //如果是左子树的 左叶子结点，那么就将其加入结果
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right)) { //如果是右子树 并且不是右叶子结点
            ans += dfs(node->right);
        }
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
};

//广度优先搜索
class Solution1 {
public:
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                if (isLeafNode(node->left)) {
                    ans += node->left->val;
                }
                else {
                    q.push(node->left);
                }
            }
            if (node->right) {
                if (!isLeafNode(node->right)) {  // 如果是叶子节点，就不放了，因为不存在左叶子节点
                    q.push(node->right); // 如果存了，会把这种叶子节点也加上了
                }
            }
        }
        return ans;
    }
};
int main()
{

    
    return 0;
}

