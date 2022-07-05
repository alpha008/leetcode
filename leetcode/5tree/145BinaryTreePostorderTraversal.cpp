#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<stdio.h>
#include "tree.h"
#include "helpvector.h"
using namespace std;
class Solution {
public:
/*********************************************************************************************
普通迭代法，后续遍历
**********************************************************************************************/
vector<int> postTravel(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode*> s;
    if(!root)
        return result;
    s.push(root);
    while (!s.empty())
    {
        auto node = s.top();
        result.push_back(node->val);   // 根结点
        if(node->left) s.push(node->left);  // 左子树
        if(node->right) s.push(node->right);  // 右子树
    }
    reverse(result.begin(),result.end());
    return result;
}
// 统一迭代法后序遍历
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
            s.push(node); 
            s.push(nullptr);
            if(node->right != nullptr) s.push(node->right);  // 右边
            if(node->left  != nullptr) s.push(node->left);   // 左边
        }else{
            s.pop();
            node = s.top();
            result.push_back(node->val);
            s.pop();
        }
    }
    return result; 
}
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
};


int main()
{
    vector<int> vecTreeNode1 = {1,2,3};
    TreeNode *root1 = createTree(vecTreeNode1);
    return 0;
}