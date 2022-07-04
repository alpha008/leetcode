#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<limits.h>
#include<algorithm>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/**********************************************************************************************
验证是否为搜索二叉树
节点的左⼦树只包含⼩于当前节点的数。
节点的右⼦树只包含⼤于当前节点的数。
所有左⼦树和右⼦树⾃身必须也是⼆叉搜索树
验证二叉树是为二叉搜索树
前序遍历，然后判断是否为递增

作者：carlsun-2
链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/solution/530-er-cha-sou-suo-shu-de-zui-xiao-jue-dui-chai-yo/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
***********************************************************************************************/
class Solution1 {
private:
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val); // 将二叉搜索树转换为有序数组
        traversal(root->right); // 中序遍历，二叉树为顺序递增关系
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        traversal(root);
        if (vec.size() < 2) return 0;
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); i++) { // 统计有序数组的最小差值
            result = min(result, vec[i] - vec[i-1]);
        }
        return result;
    }
};

class Solution{
public:
    vector<int> vec;
    void Travel(TreeNode*root)
    {
        if(root == nullptr) return;
        Travel(root->left);
        vec.push_back(root->val);
        Travel(root->right);
    }
    int getMinimumDifference(TreeNode* root){
        vec.clear();
        Travel(root);
        if(vec.empty()) return 0;
        int res = INT32_MAX;
        for(int i = 1; i < vec.size(); i ++)
        {
            res = min(res, vec[i] - vec[i-1]);
        }
        return res;
    }
};

int main()
{
    vector<int> vecTreeNode = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode *root = createTree(vecTreeNode);
    return 0;
}