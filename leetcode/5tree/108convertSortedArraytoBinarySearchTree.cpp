
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdio.h>
#include "tree.h"
using namespace std;
/*************************************************************************************
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵高度平衡二叉搜索树。
高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 的二叉树。
108 与 109 十分类似

作者：carlsun-2
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-er-ch-9876/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
这个答案得分比较高
**************************************************************************************/
class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + ((right - left) / 2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};


int main()
{

    return 0;
}



