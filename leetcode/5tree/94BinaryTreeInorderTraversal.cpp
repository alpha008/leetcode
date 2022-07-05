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
    while(cur != nullptr || !s.empty())
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
    {  //入栈的时候已经是按照中序遍历的方式入栈了，在需要遍历的位置添加标记，然后按照出栈顺序遍历即可
        auto node = s.top(); 
        if(node != nullptr){
            s.pop();
            if(node->right != nullptr) s.push(node->right);  // 右边
            s.push(node);   
            s.push(nullptr);
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
};

int main()
{
    vector<int> vecTreeNode1 = {1,2,3};
    Solution ab;

    TreeNode *root1 = createTree(vecTreeNode1);
    vector<int> result1 = ab.inorderTravel(root1);
    return 0;
}