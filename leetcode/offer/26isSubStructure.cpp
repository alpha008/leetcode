#include<iostream>
#include<vector>
#include<unordered_map>
#include"tree.h"
using namespace std;
/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/yi-pian-wen-zhang-dai-ni-chi-tou-dui-che-uhgs/
*/

class Solution {
public:

        // hasSubStructure函数是判断如果A,B根节点相同，B是不是A的子结构
    bool hasSubStructure(TreeNode*A, TreeNode*B)
    {
        if (!B)        //递归结束条件1：A的一个节点B的对应位置没有,可以认为是子结构
            return true;
        if (!A || A->val != B->val)  //递归结束条件2：B的一个节点A的对应位置没有 / A,B对应位置节点值不同，此时必然不可能是子结构
            return false;
        return hasSubStructure(A->left, B->left) && hasSubStructure(A->right, B->right); //返回值：继续在对应位置递归判断
    }


    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (!A || !B)   //特殊判断
            return false;
        // 根节点相同的话直接进入比较，根节点不相同看B是不是A的左/右子树的子结构
        return hasSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
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