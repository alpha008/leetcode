#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<deque>
#include "helpvector.h"
using namespace std;

/***********************************************************************
给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。
示例 1：
输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：
输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
示例 3：
输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

记 s 中，任一个长度为 words 中元素长度的子串，为一个窗口
解题步骤如下：

使用哈希表记录 words 里面元素的个数，两个作用：1)判断words中是否存在某子串；2)判断words中某子串的个数
判断第一个字母开始的窗口是否存在于words里
若存在：对窗口进行 n 次( n 等于 words 里元素个数)移动，对每一个窗口进行判断，若该窗口子串存在且其个数大于 0，认为该窗口匹配成功，将其个数减 1，窗口向后移动一个步长
若 n 次窗口都匹配成功，将 i 的值放入ans
对 s 的后续字母重复第 2.3.4 步

作者：climite
链接：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/6bu-jie-jue-kun-nan-ti-ji-xiang-xi-dai-m-ohv6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
************************************************************************/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans={};
        //len将是我们后续“窗口”移动的步长
        int len=words[0].size();
        //若s的长度比“窗口”的长度还要短，输出{}
        if(len>s.size()) return ans;
        //使用哈希表记录words里面元素的个数，两个作用：1)判断words中是否存在某子串；2)判断words中某子串的个数
        unordered_map<string,int> mymap;
        for(int i=0;i<words.size();i++)
            mymap[words[i]]++;
       
        //遍历字符串s
        for(int i=0;i<=s.size()-len;i++){
            //若以i开头的子串不存在于哈希表中，也就无需后续比较，直接continue
            if(mymap.find(s.substr(i,len))==mymap.end()) continue;
            //若存在：
            //由于mymap和i后续还要用到，不能对其进行更改，故定义两个临时变量：哈希表tmp、整型j
            unordered_map<string,int> tmp=mymap;
            int j=i;
            //对每一个“窗口”进行判断，若该窗口子串存在且其个数大于0，将其个数减1，窗口向后移动一个步长，否则退出循环
            for(int count=words.size();count>0;count--){
                string a=s.substr(j,len);
                if(tmp.find(a)==tmp.end() || tmp[a]==0) break; 
                else{
                    j+=len;
                    tmp[a]--;
                }      
                //若直到进行了 words.size() 个窗口的判断子串都存在，匹配成功，将 i 的值放入ans         
                if(j==i+len*words.size()) ans.push_back(i);                
            }
        }
        return ans;
    }
};

int main()
{


    return 0;
}
