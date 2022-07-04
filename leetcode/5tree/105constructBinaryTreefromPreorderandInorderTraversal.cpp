#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include "tree.h"
using namespace std;
/*******************************************************
 preorder = [3,9,20,15,7],
 inorder = [9,3,15,20,7]
 深刻理解前序  中序  后序 遍历顺序
*********************************************************/
class Solution {
public:
   TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0 || inorder.size() ==0)
            return NULL;
        TreeNode *root = buildTree(preorder, 0 , preorder.size()-1,inorder,0 ,inorder.size()-1 );
        return root;
   }
   TreeNode * buildTree(vector<int> &preorder,int preleft, int preright, vector<int> &inorder,int inleft ,int inright){
        if(preleft > preright || inleft > inright)
            return NULL;
        // 通过前序遍历得到的根节点  分割中序遍历中的左右子树
        auto it = find(inorder.begin(),inorder.end(), preorder[preleft]);
        int index = it - inorder.begin();
        TreeNode * root =  new  TreeNode(preorder[preleft]);
        // 分割左右子树 前序  和   中序的左右子树
        root->left =  buildTree(preorder,preleft + 1, preleft + index - inleft,inorder, inleft, index - 1);
                                        // 剔除根节点
        root->right = buildTree(preorder,preright  + index - inright + 1, preright, inorder, index + 1,inright);
        return root;
   }
};

int main()
{
    vector<int> vecTreeNode1 = {1,2,3};
    TreeNode *root1 = createTree(vecTreeNode1);
    vector<vector<int> >result1 = levelOrder33(root1);
    return 0;
}