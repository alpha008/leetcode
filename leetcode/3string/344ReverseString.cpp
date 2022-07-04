#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        //  reverse(s.begin(),s.end());
        int left = 0, right = s.size() - 1;
        while (left < right) 
        {
            swap(s[left++],s[right--]);

        }
    }
};

void reverStr(string &str)
{
    int left = 0;
    int right = str.size() -1 ;
    while (left < right)
    {
        char temp = str[left];
        str[left++] = str[right];
        str[right--] = temp; 
    }
}
int main()
{
    string str = "hello world";
    cout << "origin str :" << str << endl;
    reverStr(str);
    cout << "now str :" << str << endl;
    cout << "hello " << endl;
    return 0;
}