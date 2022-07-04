#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/**********************************************************************************************
求二叉树的最近公共最先
两个节点p 和 q
如果左子树出现p，右子树出现q
如果左子树出现q，右子树出现p   那么该节点为最近的公共最先

在递归函数有返回值的情况下：如果要搜索⼀条边，递归函数返回值不为空的时候，⽴刻返回，如果搜索整个树，
直接⽤⼀个变量left、 right接住返回值，这个left、 right后序还有逻辑处理的需要，也就是后序遍历中处理中间节
点的逻辑（也是回溯） 。
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 
的深度尽可能大（一个节点也可以是它自己的祖先）。”
示例 1：
             3
      5             1
  6      2      0      8
n  n   7  4   n  n   n   n 

输入：root = [3,5,1,6,2,0,8,null,null,7,4],    p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***********************************************************************************************/
class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) {  // 判断p q  节点是否在二叉树内
            return root;
        }
        if (root != nullptr){
            TreeNode *lNode = lowestCommonAncestor(root->left, p, q);
            TreeNode *rNode = lowestCommonAncestor(root->right, p, q);
            if (lNode != nullptr && rNode != nullptr)
                return root;
            else if(lNode == nullptr) {//两个都在右子树
                return rNode;
            }
            else { //两个都在左子树里面
                return lNode;
            }
        }
        return nullptr;
    }
};

int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    return 0;
}

