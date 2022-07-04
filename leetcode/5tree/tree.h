#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}

    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
/**********************************************************************************************************
1. 手动创建一颗完全二叉树，根据数组
**********************************************************************************************************/
TreeNode* createTree(vector<int>nums)
{
    int n = nums.size();
    TreeNode *ptree=(TreeNode*)malloc(sizeof(TreeNode )*n);
    int i;    
    // 初始化所有节点 
    for(i = 0;i< n; i++)
    {
        ptree[i].val= nums[i];//数组a只起到一个赋值的作用
        ptree[i].left = NULL;
        ptree[i].right= NULL;
    }
    for(i = 0; i<= n/2-1; i++)  //原来的父亲节点范围为1~n/2,现在0~n/2-1,所以注意n/2要取到等
    {
        if(2*i+1 <= n-1)
            ptree[i].left=&ptree[2*i+1];//把第2*i+1个结点的地址赋给左孩子
        if(2*i+2 <= n-1)
            ptree[i].right=&ptree[2*i+2];
    }
    return ptree;
}
/**********************************************************************************************************
2. 打印二维矩阵
**********************************************************************************************************/
void printMatrix(vector<vector<int>> &display)
{
    for(int i = 0; i < display.size();i++)
    {
        //cout << "i:" << i << endl;
        for(int j = 0;j < display[i].size();j++)
        {
            //cout << "j:" << j << endl;
            cout << display[i][j] << " " ;
        }
        cout << endl;
    }
}

// 二叉树层序遍历，这个方法比较通俗易懂
vector<vector<int> > levelOrder33(TreeNode *root)
{
    vector<vector<int> > ret;
    if(!root)
        return ret;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int cursize = q.size();
        ret.push_back(vector<int>());
        for(int i = 0; i < cursize; i++)
        {
            auto node = q.front();
            ret.back().push_back(node->val);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return ret;
}