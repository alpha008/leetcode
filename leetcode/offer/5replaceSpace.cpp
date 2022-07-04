#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for(int i = 0; i< s.size(); i++){
            if(s[i] == ' ')
                res += "%20";
            else
                res +=s[i];
        }
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