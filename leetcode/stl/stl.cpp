#include <iostream>
#include <algorithm>
#include <vector>
/**************************************************************************************
lower_bound  寻找 第一个 target <= element的位置
Search for first element x such that i ≤ x
左边都比给定值小
**************************************************************************************/

void test01()
{
    const std::vector<int> data = {1, 2, 3, 4, 5, 6 };
    for(int i = 0; i < 8 ; ++i)
    {  // Search for first element x such that i ≤ x
        auto lower = std::lower_bound(data.begin(), data.end() , i );
        if(lower != data.end()){
            std::cout << i << " <= " << *lower << " at index " << std::distance(data.begin(), lower) << std::endl;
        }else{
            std::cout << i << " <= not found" << std::endl; 
        }
    }
}
/***************************************************************************************
upper_bound 
左闭右开 第一个大于 target的位置
Search first element that is greater than i
Search for first element x such that i < x
右边都比给定值大
***************************************************************************************/
void test02()
{
    const std::vector<int> data = {1, 2, 3, 4, 5, 6};
    for(int i = 0; i < 7; ++i){
        auto upper = std::upper_bound(data.begin(), data.end() , i);
        if(upper != data.end()){
            std::cout << i << " < first, " << *upper << " at index " << std::distance(data.begin(), upper) << std::endl;
        }else{
            std::cout << i << " not found " << std::endl;
        }
    }
}
int main()
{
     test01();
    //test02();
    return 0;

}
  
