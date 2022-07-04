#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include "tree.h"
using namespace std;
class solution{
public:
    bool isSameTree(TreeNode *p , TreeNode *q)   // 递归做法
    {
        if(!p && !q) return true;     //左右子树同时为空
        if(!p || !q) return false;    //两者肯定不可能同时为空， 两者中有一个空就判定为false 
        return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
    bool isSameTree1(TreeNode *p , TreeNode *q)   // 使用一个栈
    {
        stack<TreeNode*> st;
        st.push(p);
        st.push(q);
        while(!st.empty())
        {
            p = st.top(); st.pop();
            q = st.top(); st.pop();
            if(!p && !q) continue;
            if(!p || !q) return false;
            if(p->val != q->val) return false;
            st.push(p->left);
            st.push(q->left);

            st.push(p->right);
            st.push(q->right);
        }
        return true;
    }
};
int main()
{
    vector<int> vecTreeNode1 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,14};
    TreeNode *root1 = createTree(vecTreeNode1);
    vector<vector<int> >result1 = levelOrder33(root1);
    printMatrix(result1);

    vector<int> vecTreeNode2 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,14};
    TreeNode *root2 = createTree(vecTreeNode2);
    vector<vector<int> >result2 = levelOrder33(root2);
    printMatrix(result2);

    return 0;
}
