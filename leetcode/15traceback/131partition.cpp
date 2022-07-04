#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/******************************************************************************
示例 1
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：
输入：s = "a"
输出：[["a"]]
*********************************************************************************/
class Solution {
private:
vector<vector<string>> result;
vector<string> path; // 放已经回⽂的⼦串
    void backtracking (const string& s, int startIndex) {
        // 如果起始位置已经⼤于s的⼤⼩，说明已经找到了⼀组分割⽅案了
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) { // 是回⽂⼦串
                // 获取[startIndex,i]在s中的⼦串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else { // 不是回⽂，跳过
                continue;
            }
            backtracking(s, i + 1); // 寻找i+1为起始位置的⼦串
            path.pop_back(); // 回溯过程，弹出本次已经填在的⼦串
        }
    }
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
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
