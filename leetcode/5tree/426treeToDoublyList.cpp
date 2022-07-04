#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include "tree.h"
#include "list.h"
#include "helpvector.h"
using namespace std;
/***********************************************************************************************
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
为了让您更好地理解问题，以下面的二叉搜索树为例：
我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。
对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

将二叉搜索树转换为双向链表

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。
还需要返回链表中的第一个节点的指针。

https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=23253&ru=/ta/sql-quick-study&qru=/ta/sql-quick-study/question-ranking
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***********************************************************************************************/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)                         //总是一左一右的执行
            return NULL;

        if(pRootOfTree->left == NULL && pRootOfTree->right == NULL)
            return pRootOfTree;                         //如果是叶子结点则就地返回，为空啥也不干就回来了
        TreeNode* left = Convert(pRootOfTree->left);    //找到左子树最左边叶子节点

        TreeNode* curr = left;
        while(curr != NULL && curr->right != NULL)      //找到左子树最右边节点
            curr = curr->right;                         //操作完成后往后面移动了一下
        if(curr != NULL)                                //连接根节点和左子树
        {
            curr->right = pRootOfTree;
            pRootOfTree->left = curr;
        }     
                                                        //完成最右边一个与头指针相连接
        TreeNode* right = Convert(pRootOfTree->right);  //找到右子树最左端节点
        if(right != NULL)                               //连接根节点和右子树
        {
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        return left != NULL ? left : pRootOfTree;       //这里才是递归返回的地方 ，返回最左边的位置
    }
};


int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    return 0;
}