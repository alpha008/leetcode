#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<stdio.h>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/***************************************************************
 给定⼀个不含重复元素的整数数组。⼀个以此数组构建的最⼤⼆叉树定义如下
 ⼆叉树的根是数组中的最⼤元素。
左⼦树是通过数组中最⼤值左边部分构造出的最⼤⼆叉树。
右⼦树是通过数组中最⼤值右边部分构造出的最⼤⼆叉树。

作者：carlsun-2
链接：https://leetcode-cn.com/problems/maximum-binary-tree/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-er-ch-xxox/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*****************************************************************/
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        if (nums.size() == 1) {
            node->val = nums[0];
            return node;
        }
        // 找到数组中最大的值和对应的下表
        int maxValue = 0;
        int maxValueIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->val = maxValue;
        // 最大值所在的下表左区间 构造左子树
        if (maxValueIndex > 0) {
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(newVec);
        }
        // 最大值所在的下表右区间 构造右子树
        if (maxValueIndex < (nums.size() - 1)) {
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }
        return node;
    }
};

int main()
{
    vector<int> vecTreeNode1 = {3,2,1,6,0,5};
    Solution ab;
    TreeNode *root1 = ab.constructMaximumBinaryTree(vecTreeNode1);
    vector<vector<int> >result = levelOrder33(root1);
    printMatrix(result);
    return 0;
}



