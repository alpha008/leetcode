#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numWays(int n) {
        int prev = 0;
        int cur = 1;
        for(int i = 1; i <= n ; ++i){
            int tmp = cur;
            cur = (prev + cur)%1000000007;
            prev = tmp;
        }
        return cur;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target =  9;
    vector<int> res;

    cout << "hello " << endl;
    return 0;
}