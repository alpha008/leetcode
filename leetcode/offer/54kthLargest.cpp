#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include"list.h"
#include"tree.h"
using namespace std;
/*
给定一棵二叉搜索树，请找出其中第k大的节点。

作者：zxxz-2
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/solution/zhong-xu-bian-li-by-zxxz-2-dimg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flag = false;
    int kthLargest(TreeNode* root, int k) {
        std::vector<int> ans;
        std::stack<TreeNode*> tree_st;
        while(!tree_st.empty() || root != NULL) {
            while(root != NULL) {
                tree_st.push(root);
                root = root->left;
            }
            TreeNode* tmp = tree_st.top();
            tree_st.pop();
            ans.push_back(tmp->val);
            root = tmp->right;
        }
        return ans[ans.size() - k];
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