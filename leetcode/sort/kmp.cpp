#include<iostream>
#include<vector>
#include<string>
#include"helpvector.h"

using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];  // 循环跳转
            }
            if (s[i] == s[j]) {   // 如果相等  如果不相等
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) 
        {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];  // 不匹配的话，跳转到前面的位置
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main()
{
    string  haystack = "aabaabaafa";
    string  needle = "aabaaf";
    Solution ab;   
    int res = ab.strStr(haystack, needle);
    string str = haystack.substr(res, needle.size() );
    cout << "str is :" << str << endl;
    cout << "res is :" << res << endl;
    cout << "hello" << endl;
    return 0;
}



