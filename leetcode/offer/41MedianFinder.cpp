#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    priority_queue<int, vector<int>, greater<int>> up; //小顶堆
    priority_queue<int> down; //大顶堆
    void addNum(int num) {
        if (down.empty() || num <= down.top()) down.push(num); //插入元素小于大顶堆堆顶，插入大顶堆中。
        else up.push(num); //否则插入小顶堆中。
        //调整大顶堆和小顶堆元素
        if (down.size() == up.size() + 2) {//大顶堆元素个数大于小顶堆元素个数超过一个时进行调整。
            up.push(down.top());
            down.pop();
        } else if (up.size() == down.size() + 1) {//小顶堆元素个数大于小顶堆元素个数一个时，就要进行调整，为了使中点保持在大顶堆上。
            down.push(up.top());
            up.pop();
        }
    }
    double findMedian() {
        if ((down.size() + up.size()) % 2) return down.top(); //元素总数为奇数时。
        return (down.top() + up.top()) / 2.0; //元素总数为偶数时。
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}