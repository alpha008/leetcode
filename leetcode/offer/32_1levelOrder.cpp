#include<iostream>
#include<vector>
#include<unordered_map>
#include"tree.h"
using namespace std;
/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) 
    {
        vector<int> rest;
        queue<TreeNode*> q;//使用队列先进先出的特性，实现二叉树的广度优先搜索BFS
        if(!root) return rest;
        q.push(root);//根节点入队

        while(!q.empty())
        {
             TreeNode* node =q.front();//暂存队头元素
             q.pop();//队头元素出队
             rest.push_back(node->val);
             //若当前结点的左右子节点不为空，则先左后右将其子节点入队
             if(node->left) q.push(node->left);
             if(node->right) q.push(node->right);
        }

        return rest;

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