#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include<algorithm>
#include "tree.h"
using namespace std;
/********************************************************************************
给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。
这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。
每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
输入: 
          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
输出: 8
解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
注意: 答案在32位有符号整数的表示范围内。
链接：https://leetcode-cn.com/problems/maximum-width-of-binary-tree

每层的索引值都从1开始，也就是如果某一个节点的索引为i，
则其左孩子索引为(2*i - left )       减去最左边的值，保留相对位置
则其右孩子索引为(2*i - left + 1 )   减去最左边的值，保留相对位置
这样可以重置索引，避免二叉树节点过多导致索引值溢出。
          1
    2          3
 4    5     6       7
8 9 10 11 12  13  14  15 
**********************************************************************************/
// 二叉树的最大宽度
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push(pair<TreeNode*,int>(root, 1));
        int result = INT32_MIN;
        while(!q.empty())
        {
            int cursize = q.size();
            int left = q.front().second; //当前层头节点的下标
            int right = 0 ;
            for(int i = 0; i < cursize ; i ++)   //left 和 right 决定下一层的index下标
            {
                auto node = q.front().first;
                right = q.front().second;
                q.pop();                                         // 每层的头节点该位置index为0
                if (node->left != nullptr)  q.push({node->left,  2 * right - 2 *left }); //防止索引位置太大溢出
                if (node->right != nullptr) q.push({node->right, 2 * right - 2 *left + 1});
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    vector<int> vecTreeNode1 = {1,2,3,4,5,6,7};
    TreeNode *root = createTree(vecTreeNode1);
    vector<vector<int> >result1 = levelOrder33(root);
    printMatrix(result1);
    Solution ab;

    int res = ab.widthOfBinaryTree(root);
    cout << "res:" << res << endl;
    return 0;
}



