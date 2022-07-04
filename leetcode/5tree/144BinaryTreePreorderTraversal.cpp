#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include "tree.h"
#include "helpvector.h"
using namespace std; 


class Solution {
public:
    // 
    void preTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val); // 中
        preTraversal(cur->left, vec); // 左
        preTraversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preTraversal(root, result);
        return result;
    }
    void inOrderTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        inOrderTraversal(cur->left, vec); // 左
        vec.push_back(cur->val); // 中
        inOrderTraversal(cur->right, vec); // 右
    }

    void postTraversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        postTraversal(cur->left, vec); // 左
        postTraversal(cur->right, vec); // 右
        vec.push_back(cur->val); // 中
    }

    /*********************************************************************************************
    统一迭代法前序遍历  二叉树的前序遍历是最符合思维逻辑的
    **********************************************************************************************/
    vector<int> prevOrderTravel(TreeNode*root)
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
                if(node->right != nullptr) s.push(node->right);   // 右边
                if(node->left  != nullptr) s.push(node->left);    // 左边
                s.push(node);    // 根节点
                s.push(nullptr);
            }else{                      // 如果等于空说明遇到了根节点
                s.pop();
                node = s.top();
                result.push_back(node->val);
                s.pop();
            }
        }
        return result; 
    }
    // 普通迭代写法，使用一个栈
    vector<int> preOrderTravel1(TreeNode*root)
    {
        stack<TreeNode*> st;
        vector<int> result;
        if(root == nullptr)  return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode * node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->right != nullptr) st.push(node->right);
            if(node->left != nullptr) st.push(node->left);
        }
        return result;    
    }
};


int main()
{
    vector<int> vecTreeNode1 = {1,2,3};
    TreeNode *root1 = createTree(vecTreeNode1);
    return 0;
}



