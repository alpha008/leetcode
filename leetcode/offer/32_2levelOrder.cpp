#include<iostream>
#include<vector>
#include<queue>
#include"tree.h"
#include<unordered_map>
using namespace std;
/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
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
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode *> points;
        points.push(root);
        while(points.size()){
            int col=points.size();
            vector<int> ans1;
            for(int i=0;i<col;i++){
                TreeNode *temp=points.front();
                points.pop();
                ans1.push_back(temp->val);
                if(temp->left) points.push(temp->left);
                if(temp->right) points.push(temp->right);
            }
            ans.push_back(ans1);
        }
        return ans;
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