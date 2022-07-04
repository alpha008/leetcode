#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
/***************************************************
此种题目分为两类： 
一类是有前置或后置空格的
一类是没有前置或后置空格
***************************************************/
void preSpace()
{
    string s;
    s +=" ";  // 这里在最后一个字符位置加上空格，这样最后一个字符串就不会遗漏
    string temp = ""; //临时字符串
    vector<string> result; //字符串数组
    for(char ch :s)
    {
        if(ch == ' ') //遇到空格
        {
            if(!temp.empty())//临时字符串非空
            {
                result.push_back(temp); 
                temp.clear(); //清空临时字符串
            }
        }  
        else
        {
            temp +=ch;
        } 
    }
}
void lastSpace()
{
    string s;
    s +=" ";  // 这里在最后一个字符位置加上空格，这样最后一个字符串就不会遗漏
    string temp = ""; //临时字符串
    vector<string> result; //字符串数组
    for(char ch :s)
    {
        if(ch == ' ') //遇到空格
        {
            result.push_back(temp); 
            temp.clear(); //清空临时字符串
        }  
        else
        {
            temp +=ch;
        } 
    }
}
// 58. 最后一个单词的长度
// xxaabb cc dd eex    x代表空格
// aabb cc dd eex x代表空格
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

//557 反转字符串中的每个单词
string reverseWords(string s)
{
    if(s.empty())
        return s;
    s += " ";
    string temp;
    vector<string>result;
    for(char ch :s )
    {
        if(ch == ' '){
            if(!temp.empty()){
                result.push_back(temp);
                temp.clear();
            }
        }
        else{
            temp += ch;
        }   
    }
    s.clear();
    for(string & str : result){
        reverse(str.begin(),str.end());
        s += str + ' ';
    }
    s.pop_back();
    return s;
}
//剑指offer58.反转一个句子 并把前置和后置空格去掉
string revesSentences(string s)
{
    if(s.empty())
        return s;
    string temp;
    vector<string> result;
    s += "";
    for(char ch :s)
    {
        if(ch == ' ')
        {
            if(!temp.empty()){
                result.push_back(temp);
                temp.clear();
            }
        }
        else{
            temp += ch;
        }
    }
    s.clear();
    reverse(result.begin(),result.end());
    for(string str:result)
    {
        s+= str+' ';
    }
    s.pop_back();
    return s;
}
//1816.截断一个句子只有前k个单词
string trimSentense(string s, int k)
{
    if(s.empty())
        return s;
    s += " ";
    string temp;
    vector<string> res;
    for(char ch :s )
    {
        if(ch == ' ')
        {
            if(!temp.empty())
            {
                res.push_back(temp);
                temp.clear();
            }
        }   
        else{
            temp+=ch;
        }
    }
    int i = 0;
    for( i = 0 ;i < k && i < res.size() ; i++)
    {
        temp += res[i] + ' ';
    }
    if(i < k)
    {
        return "not exist";
    }
    else
    {
        temp.pop_back();
        return temp;
    }
}
// 1805.字符串中不同整数的数目
int countDiffInt(string word)
{
    set<string>s;
    if (word.empty())
        return 0;
    word += "a";    
    string temp;
    vector<string> res;
    for(char ch : word)
    {
        if(isalpha(ch)){
            if(!temp.empty()){
                s.insert(temp);
                temp.clear();
            }
        }
        else{
            if(temp == "0"){
                temp.clear();
            }
            temp += ch;
        }
    }
    for(set<string>::const_iterator it = s.begin(); it != s.end();it++)
    {
        cout << "number is :" << *it << endl;
    }
    return s.size();
}
/*
示例 1：
输入：word = "a123bc34d8ef34"
输出：3
解释：不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
示例 2：
输入：word = "leet1234code234"
输出：2
示例 3：
输入：word = "a1b01c001"
输出：1
解释："1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
*/
//1455， 检查单词是否为句子中其它单词的前缀，并返回该单词索引
int isPreFixOfWord(string s,string word)
{
    if(s.empty())
        return -1;
    string temp = "";
    vector<string> res;
    for(char ch :s)
    {
        if(ch == ' ')
        {
            if(!temp.empty())
            {
                res.push_back(temp);
                temp.clear();
            }
        }
        else
        {
            temp+=ch;
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        if(0 == res[i].find(word))
            return i + 1;
    }
    return -1;
}
//1859.根据句子单词末尾的数字排序
string sortSentence(string s)
{
    if(s.empty())
        return s;
    s += " ";
    string temp = "";
    vector<string> res;
    for(char ch :s )
    {
        if(ch == ' ')
        {
            if(!temp.empty()){
                res.push_back(temp);
                temp.clear();
            }
        }
        else{
            temp+=ch;
        }
    }
    sort(res.begin(),res.end(),[&](string &a,string &b){ return a.back() < b.back();} );
    s.clear();
    for(auto str:res)
    {
        str.pop_back();
        s += str + " ";
    }
    s.pop_back();
    return s;
}
//1592. 重新排列单词的间的空格
/*
示例 1：

输入：text = " this is a sentence "
输出：“this is a sentence”
解释：总共有 9 个空格和 4 个单词。可以将 9 个空格平均分配到相邻单词之间，相邻单词间空格数为：9 / (4-1) = 3 个。
示例 2：

输入：text = " practice makes perfect"
输出："practice makes perfect "
解释：总共有 7 个空格和 3 个单词。7 / (3-1) = 3 个空格加上 1 个多余的空格。多余的空格需要放在字符串的末尾。
示例 3：

输入：text = “hello world”
输出：“hello world”
平均分配每个单词的空格，空格仅跟在单词的后面
*/
string reorderSpace(string s)
{
    if(s.empty())
        return s;
    string temp;
    vector<string> res;
    s += "";
    int cnt = 0;
    for(char ch : s)
    {
        if(ch == ' ')
        {
            cnt++;
            if(!temp.empty()){
                res.push_back(temp);
                temp.clear();    
            }
        }
        else{
            temp += ch;
        }
    }
    s.clear();
    if(res.size() == 1)
    {
        s += res[0];
        s.insert(s.size(),cnt,' ');
        return s;
    }
    int n = res.size();
    int blank = cnt / (n - 1) ;
    int remain = cnt - blank * (n - 1);
    for(int i = 0; i < res.size(); i++)
    {
        s += res[i];
        s.insert(s.size(),blank, ' ');
    }
    if(remain > 0)
        s.insert(s.size(),remain,' ');
    return s;
}
int main()
{
    //1.求出最后一个单词长度
    string s  = "   123 aa vv bb";
    cout << "origin s:" << s <<endl;
    lengthOflastWord(s);
    //2.反转一个字符串中的每个单词
    s = "av gf de fg";
    cout << "origin s:" << s <<endl;
    cout << "reverse every word:" << reverseWords(s) <<endl;
    //3.反转一个句子 并把前置和后置空格去掉
    s = " abd df ggf a ";
    cout << "origin s:" << s << endl;
    cout << "revers sentences is :" << revesSentences(s) << endl;
    //4.截断一个句子只有前k个单词
    s = "aa bb cc dd ee ff";
    int k = 8;
    cout << "origin string is :" <<  s << endl;
    cout << "trim k:" << k << " left is :" << trimSentense(s, k)<< endl;
    //5.计算字符串中不同整数的数目
    s = "a123bc34d8ef34";
    cout << "origin s is :" <<  s << endl;
    cout << "dif number is :" << endl; 
    cout << countDiffInt(s) << endl;
    //6.查找该单词是否为其它句子中单词的前缀
    s = "i love eating burger";
    cout << "origin s is :" << s << endl;
    cout << "indx is " << isPreFixOfWord(s, "eating") << endl;
    //7.将句子中的单词根据单词后面的数字排序
    s = "i1 love3 eatring2 burger";
    cout << "origin s is:" << s <<endl;
    cout << sortSentence(s) << endl;
    s =  "    this    is a    sentence    ";
    cout << "origin s is:" << s <<endl;
    cout << "reorder is :" << reorderSpace(s) << endl;
    cout << "hello word" << endl;
    //8.
    return 0;
}


