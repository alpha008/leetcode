#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<stdio.h>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/********************************************************************************************
翻转一棵二叉树。
示例：
输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/invert-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**********************************************************************************************/
class solution{
public:
    //1. 递归遍历 反转二叉树   
    TreeNode* invertTree2(TreeNode*root)
    {
        if(root == nullptr) return root;
        swap(root->left,root->right);
        invertTree(root->left);   // 一左一右
        invertTree(root->right);
    }
    //2. 前序遍历 迭代法反转  使用栈 来存储未翻转的节点
    TreeNode* invertTree1(TreeNode* root)
    {
        if(root == nullptr) return root;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            auto node =  s.top();
            s.pop();
            swap(node->left , node->right);
            if(node->right != nullptr) s.push(node->right);
            if(node->left != nullptr) s.push(node->left);
        }
        return root;
    }
    //3. 层序遍历方法反转二叉树  使用队列来存储中间节点
    TreeNode* invertTree(TreeNode *root)
    {   
        queue<TreeNode *>queue;
        if (root != nullptr)
            queue.push(root);
        while (!queue.empty())
        {
            int n = queue.size();
            for (int i = 0; i < n; i++)
            {
                auto node = queue.front();
                queue.pop();
                swap(node->left,node->right);  //精华之处
                if(node->left != nullptr) queue.push(node->left);
                if(node->right != nullptr) queue.push(node->right);
            }
        }
        return root;
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



