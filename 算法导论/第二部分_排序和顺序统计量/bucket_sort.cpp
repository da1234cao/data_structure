/**
 * 桶排序
 * 具体问题，具体对待
 * 下面代码仅考虑：输入数据[0,1)的正态分布。采用10个桶
 * 1. 当然可以：采用bucket_num，(MAX-MIN)/bucket_num来判断区间，以放入哪个桶。
 * 2. 桶的命名，不能命令成bucket1,bucket2这样傻乎乎的名字。可以用链表，也可以用用vector<vector<>>
*/

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

template<class T>
void print_vector(vector<T> &v){
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}



int main(void){
    // 创建nums个[0,1)随机数
    int nums = 10;
    vector<double> v(nums,0);
    srand(time(NULL));
    for(int i=0; i<nums; i++)
        v[i]=rand()%100/100.0;//
    print_vector<double>(v);
    return 0;
}