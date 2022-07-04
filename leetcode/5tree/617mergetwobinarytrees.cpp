#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/**********************************************************************************************
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，
那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
示例 1:
输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***********************************************************************************************/
//深度优先搜索   还是递归写法简单
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {   //递归写法相对比较容易理解
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};


//广度优先搜索
class Solution1 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        } // 当其中一颗树为空时
        auto merged = new TreeNode(t1->val + t2->val);
        auto q      = queue<TreeNode*>();
        auto queue1 = queue<TreeNode*>();
        auto queue2 = queue<TreeNode*>(); // 使用三个队列存储中间状态
        q.push(merged); // 将新结点存入队列，作为新生成的二叉树的头结点 
        queue1.push(t1);
        queue2.push(t2); // 合并之后的树   左子树  右子树
        while (!queue1.empty() && !queue2.empty()) {
            auto node = q.front(), node1 = queue1.front(), node2 = queue2.front();
            q.pop();
            queue1.pop();
            queue2.pop(); // 取出队首元素  左子树       右子树
            auto left1 = node1->left, left2 = node2->left, right1 = node1->right, right2 = node2->right;
            if (left1 != nullptr || left2 != nullptr) {
                if (left1 != nullptr && left2 != nullptr) {  // 左右都不为空
                    auto left = new TreeNode(left1->val + left2->val);
                    node->left = left;  // 将结点向新的树结点中挂靠
                    q.push(left);
                    queue1.push(left1);
                    queue2.push(left2);
                } else if (left1 != nullptr) {  // 当树1的左结点不为空   树2的左结点为空
                    node->left = left1;
                } else if (left2 != nullptr) {  // 当树1的左结点为空     树2的左结点不为空
                    node->left = left2;
                }
            }
            if (right1 != nullptr || right2 != nullptr) {
                if (right1 != nullptr && right2 != nullptr) {  // 树1的右结点不为空 且  树2的右结点不为空
                    auto right = new TreeNode(right1->val + right2->val);
                    node->right = right;
                    q.push(right);
                    queue1.push(right1);
                    queue2.push(right2);
                } else if (right1 != nullptr) { // 当树1的右结点不为空   树2的右结点为空
                    node->right = right1;
                } else {                        // 当树1的右结点不为空   树2的右结点不为空
                    node->right = right2;
                }
            }
        }
        return merged; // 返回合并之后的结点
    }
};



int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);

    
    return 0;
}

