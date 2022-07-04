#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
/*
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同
示例 1：
输入：s = "bcabc"
输出："abc"
示例 2：
输入：s = "cbacdcbc"
输出："acdb"
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
变量简洁正确完整思路
去重用哈希集，相对顺序就像按顺序放到双端队列deq，字典序最小如bcabc
有bca和abc，遇到a，如果后面还有bc（用char2cnt表示a后面还有多少），且deqfront>a就应该popdeq并删掉哈希集，如何维护char2cnt，
先遍历一遍全部，然后b就cnt--，c就cnt--，

精确定义char2cnt，遍历到c时后面的元素出现的次数
*/


class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char>seen;
        unordered_map<char,int>char2cnt;
        deque<char>deq;
        for(auto c:s)
            char2cnt[c]++;
        for(auto c:s){
            char2cnt[c]--;
            if(seen.count(c))
                continue;
            while(!deq.empty()&&char2cnt[deq.back()]>0&&deq.back()>c){

                seen.erase(deq.back());
                deq.pop_back();
            }
            seen.insert(c);
            deq.push_back(c);
        }
        string ans;
        while(!deq.empty()){
            ans.push_back(deq.front());
            deq.pop_front();
        }
        return ans;
    }
};

int main()
{

    cout << "hello " << endl;
    return 0;
}