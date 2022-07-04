#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include "tree.h"
using namespace std;
/*******************************************************
遍历顺序 重构一棵二叉树
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
 深刻理解前序  中序  后序 遍历顺序
*********************************************************/
class construct{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        if(inorder.empty() || postorder.empty())
            return NULL;
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode *buildTree(vector<int> &inorder,int iLeft,int iRight, vector<int> &postorder,int pLeft,int pRight)
    {
        if(iLeft > iRight || pLeft > pRight)
            return NULL;
        auto iter = find(inorder.begin(),inorder.end(), postorder[pRight]);
        int index = iter - inorder.begin();  // 返回的是距离开始结点的位置，并不是个数
        TreeNode* root = new TreeNode(postorder[pRight]);
        // 从中序遍历中分割出左右子树
        // 从后序遍历中分割出左右子树
        root->left = buildTree(inorder, iLeft, index - 1, postorder, pLeft, pLeft + index  - iLeft - 1); 
                                                                    // 求出根节点距离中序起始位置节点间距离，多计算了一个根节点的位置
        root->right = buildTree(inorder, index + 1, iRight, postorder, pLeft + index - iLeft, pRight - 1);
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



