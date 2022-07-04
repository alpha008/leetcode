#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include "tree.h"
#include "helpvector.h"
using namespace std;
class Solution {
public:
    void inOrderTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        inOrderTraversal(cur->left, vec); // 左
        vec.push_back(cur->val); // 中
        inOrderTraversal(cur->right, vec); // 右
    }
    /*********************************************************************************************
    中序遍历迭代版本
    *********************************************************************************************/
    vector<int> inorderTravel(TreeNode *root)
    { 
        vector<int> result;  
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != nullptr || !s.empty())  // 当前指针或者栈不为空就继续执行
        {
            if(cur != nullptr){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top();
                s.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
    /***************************************************************************************************
    中序遍历统一风格迭代版本
    ****************************************************************************************************/
    vector<int> inorderIterTravel(TreeNode *root)
    { 
        vector<int> result;
        stack<TreeNode*> s;
        if(root != nullptr)
            s.push(root);
        while (!s.empty())
        { 
            auto node = s.top(); // 先把栈顶元素保存
            if(node != nullptr){
                s.pop();
                if(node->right != nullptr) s.push(node->right);  // 右边
                s.push(node);    // 根节点
                s.push(nullptr);
                if(node->left  != nullptr) s.push(node->left);   // 左边
            }else{   // 如果等于空说明遇到了根节点
                s.pop();
                node = s.top();
                result.push_back(node->val);
                s.pop();
            }
        }
        return result; 
    }
};

int main()
{
    vector<int> vecTreeNode1 = {1,2,3};
    Solution ab;

    TreeNode *root1 = createTree(vecTreeNode1);
    vector<int> result1 = ab.inorderTravel(root1);
    return 0;
}