#include<iostream>
#include<vector>
#include<queue>
#include"tree.h"
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
其他行以此类推。
例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;   vector<int> temp;
        if(root == NULL) return res;
        queue<TreeNode*> q; q.emplace(root);
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                TreeNode* node = q.front(); q.pop();
                temp.emplace_back(node->val);
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
            res.emplace_back(temp); temp.clear();
        }
        for(int i = 1; i < res.size(); i += 2)
            reverse(res[i].begin(), res[i].end());
        return res;
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