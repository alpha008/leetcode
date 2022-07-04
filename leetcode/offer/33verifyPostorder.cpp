#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：
输入: [1,3,2,6,5]
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool check(vector<int>& post, int start, int end ){
        if( start == end ) return true;
        // 最後一位
        int rootVal = post[end];

        // 找 1st > rootVal = 右子樹起點
        int m = -1;
        for(int i = 0 ; i < end ;++i){ if( post[i] > rootVal ){ m = i; break; } }
        // 如果沒右子樹直接回 true
        if( m == -1 ) return true;

        // 檢查右子樹即可                
        for(int idx = m; idx < end ; ++idx){
            if( post[idx] < rootVal ) return false;            
        }
        return check(post,0,end-m-1) && check(post, m , end-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        if( postorder.empty() ) return true;
        return check(postorder, 0, postorder.size()-1 );
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