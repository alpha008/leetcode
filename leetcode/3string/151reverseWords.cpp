#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**********************************************************************************************************
给你一个字符串 s ，逐个翻转字符串中的所有单词 。
单词是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。
说明：
输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
翻转后单词间应当仅用一个空格分隔。
翻转后的字符串中不应包含额外的空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***********************************************************************************************************/
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())  return s;
        vector<string> res;  // 用来存放单词
        s += " ";
        string temp = "";  // 用来组装单个单词
        for(auto ch : s)
        {
            if(ch == ' '){
                if(!temp.empty()){
                    res.push_back(temp);
                    temp.clear();
                }
            }else{
                temp += ch;
            }
        }
        s.clear();
        reverse(res.begin(), res.end());
        for(auto str : res){
            s += str + " ";
        }
        s.pop_back();  // 去掉末尾空格
        return s;
    }
};
int main()
{
    string str = "abaaba";
    Solution ab;
    string res =  ab.reverseWords(str);
    cout << "reverseWords " << res << endl;
    cout << "hello " << endl;
    return 0;
}