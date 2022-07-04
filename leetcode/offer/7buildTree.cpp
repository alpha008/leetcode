#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
根据前序和中序重建一颗二叉树
*/
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
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}