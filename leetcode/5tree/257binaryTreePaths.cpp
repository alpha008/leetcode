#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include "tree.h"
#include "helpvector.h"
using namespace std;
/*********************************************************************************************
   1
2     3 
   5  
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]
示例 2：
输入：root = [1]

作者：carlsun-2
链接：https://leetcode-cn.com/problems/binary-tree-paths/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-er-ch-cxmu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
清晰明了，简单递归到底  存储中间状态  搜集结果
这个题目不用回溯，用到了这个函数  to_string 将整数转换为字符串
/**********************************************************************************************/
class Solution {
private:
    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val); // 中  to_string()
        if (cur->left == NULL && cur->right == NULL) {
            result.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->", result);   // 左
        if (cur->right) traversal(cur->right, path + "->", result); // 右
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};
int main()
{
    return 0;
}