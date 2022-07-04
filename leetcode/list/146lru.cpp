#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        int retValue = -1;
        unordered_map<int, list<pair<int, int> > ::iterator> ::iterator it = cachesMap.find(key);
        //如果在Cacah中，将记录移动到链表的最前端
        if (it != cachesMap.end())
        {
            retValue = it->second->second;   // 通过迭代器取链表中的值
            //移动到最前端
            list<pair<int, int> > ::iterator ptrPair = it->second;
            pair<int, int> tmpPair = *ptrPair;
            listcaches.erase(ptrPair++);           // 删除值
            listcaches.push_front(tmpPair);        // 将值拿出来放在开始位置处
            cachesMap[key] = listcaches.begin();   // 移动到开头位置
        } // 通过map加快查找速度，然后从list中删除，在插入到头部，然后保存迭代器位置
        return retValue;
    }
    void put(int key, int value) {  // set函数
        unordered_map<int, list<pair<int, int> > ::iterator> ::iterator it = cachesMap.find(key);
        if (it != cachesMap.end()) //已经存在其中
        {
            list<pair<int, int> > ::iterator ptrPait = it->second;
            ptrPait->second = value;  // 通过链表迭代器取处key对应的value
            pair<int, int > tmpPair = *ptrPait;
            listcaches.erase(ptrPait);       // 删除历史记录
            listcaches.push_front(tmpPair);  // 压入链表头部
            cachesMap[key] = listcaches.begin(); // 存储key对应的迭代器，指向该起始位置
        }
        else //不存在其中
        {
            pair<int, int > tmpPair = make_pair(key, value);
            if (m_capacity == listcaches.size())        //已经满，那么删除尾部元素，然后将值更新到链表头部
            {
                int delKey = listcaches.back().first;
                listcaches.pop_back();                  //删除最后一个，删除在map中的相应项
                unordered_map<int, list<pair<int, int> > ::iterator> ::iterator delIt = cachesMap.find(delKey);
                cachesMap.erase(delIt++);
            } // 如果已经满了，删除list末尾位置，然后删除保存的迭代器
            listcaches.push_front(tmpPair);// 插入到头部
            cachesMap[key] = listcaches.begin(); //更新map中对应的迭代器
        }
    }
private:
    int m_capacity;                         //cashe的大小
    list<pair<int, int> > listcaches;           //用一个双链表存储cashe的内容  使用map加快查找的速度
    unordered_map< int, list<pair<int, int> > ::iterator> cachesMap;
};


int main(int argc, char **argv)
{
    LRUCache s(200);  // 构造函数初始化 初始化缓存大小
    int key = 0, value = 0;
    for(int i = 0; i < 10; i ++)
    {
        key = i ; value = i + 1;
        s.put(key, value);    cout << "set key:" << key << "  value " << value << endl;
        cout << "get key:" << key << "  value " << s.get(key) << endl;
    }

    return 0;
}