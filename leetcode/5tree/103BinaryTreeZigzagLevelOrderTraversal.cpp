#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include "tree.h"
using namespace std;
/**********************************************************************************************************
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
z 字型遍历二叉树
例如：
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：
[
  [3],
  [20,9],
  [15,7]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**********************************************************************************************************/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if(!root)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty())
        {
            int cursize = q.size();
            vector<int> cur;
            for(int i = 0; i < cursize; i++)
            {
                auto node = q.front();
                q.pop();
                cur.push_back(node->val);  // 当前层所有节点
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag){
                flag = false;
            }else{
                flag = true;  // 每过一层就翻转一次
                reverse(cur.begin(), cur.end());
            }
      //      cout << "res " << flag << endl;
            ret.push_back(cur);
        }
        return ret;
    }
};

int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    Solution ab;
    vector<vector<int> >res = ab.zigzagLevelOrder(root);
    printMatrix(res);
    return 0;
}