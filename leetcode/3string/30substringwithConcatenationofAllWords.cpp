#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include"helpvector.h"
using namespace std;
/************************************************************************************************************
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices
of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9]
*************************************************************************************************************/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& dict) 
    {
        size_t wordLength = dict.front().length();
        size_t dicLength = wordLength * dict.size();
        vector<int> result;
        if (s.length() < dicLength) return result;
        unordered_map<string, int> wordCount;
        for (auto const& word : dict) ++ wordCount[word];
        for (auto i = begin(s); i <= prev(end(s), dicLength); ++i) {
            unordered_map<string, int> unused(wordCount);
            for (auto j = i; j != next(i, dicLength); j += wordLength) {
                auto pos = unused.find(string(j, next(j, wordLength)));
                if (pos == unused.end() || pos->second == 0) break;
                if (--pos->second == 0) unused.erase(pos);
            }
            if (unused.size() == 0) result.push_back(distance(begin(s), i));
        }
        return result;
    }
};
int main()
{
    string s = "barfoothefoobarman";
    vector<string> dict = {"foo","bar"};
    cout << "s:" << s << endl;
    for(int i = 0; i < dict.size() ; i++)
    {
        cout << "i: " << i << " value " << dict[i] << endl;
    }
    Solution ab;
    vector<int> result = ab.findSubstring(s, dict);
    vec_print(result);
    return 0;
}
