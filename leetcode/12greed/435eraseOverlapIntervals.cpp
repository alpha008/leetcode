#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/******************************************************************************
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
示例：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*********************************************************************************/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int hash[27] = {0}; // i为字符， hash[i]为字符出现的最后位置
        for (int i = 0; i < S.size(); i++) { // 统计每⼀个字符最后出现的位置
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']); // 找到字符出现的最远边界
            if (i == right) {
            result.push_back(right - left + 1);
            left = i + 1;
            }
        }
        return result;
    }
};
int main()
{   
    vector<int> nums = {1,2,5};
    int target = 11;
    Solution ab;

    cout << "hello " << endl;
    return 0;
}
