#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        if(s.empty())
            return 0;
        s += " ";
        string temp;
        vector<string> result;
        for(char ch :s)
        {
            if(ch == ' ')
            {
                if(!temp.empty())
                {
                    result.push_back(temp);
                    temp.clear();
                }
            }
            else
            {
                temp += ch;
            }
        }
        cout << "last word is :" << result.back() << endl;
        return result.back().size();
    }
};

int main()
{

    cout << "hello " << endl;
    return 0;
}