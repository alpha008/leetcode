
/********************************************************************************************
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
你需要按照以下要求，帮助老师给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？
示例 1：
输入：[1,0,2]
输出：5
解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2：
输入：[1,2,2]
输出：4
解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
https://leetcode-cn.com/circle/article/qiAgHn/
********************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include"helpvector.h"
using namespace std;
int candy(vector<int> &ratings)
{
    vector<pair<int , int >> vv;
    for(int i = 0; i < ratings.size(); i++)
    {
        vv.push_back({ratings[i], i});
    }
    sort(vv.begin(), vv.end());
    int ans = 0;
    vector<int> getCandy(ratings.size());

    for(auto &ele : vv)
    {
        int score = ele.first;
        int idx = ele.second;
        int left = 0; int right = 0;
        // 当左边和右边都没有苹果 
        // 以当前位置左右比较
        if(idx -1 >= 0 && getCandy[idx - 1] != 0 && score > ratings[idx - 1] ){
            left = getCandy[idx - 1] +1;
        }
        if(idx + 1 < getCandy.size() && getCandy[idx + 1] != 0 && score > ratings[idx +1]){
            right = getCandy[idx + 1] +1;
        }
        //
        int count = max(left,right);
        if(count == 0 )  count ++;
        getCandy[idx] = count;
        ans = ans + count;
    }
    return ans;
}

int main()
{
    vector<int> rations = {1,0,2};
    vec_print(rations);

    int res = candy(rations);
    cout << "res is " << res  << endl;
    return 0;
}




