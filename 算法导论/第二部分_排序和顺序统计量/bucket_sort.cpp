/**
 * 桶排序
 * 适用于随机分布的数据排序。否则，有的桶里面内容太多，有的太少
 * 具体问题，具体对待
 * 下面代码仅考虑：输入数据[0,1)的正态分布。采用10个桶
 * 1. 当然可以：采用bucket_num，(MAX-MIN)/bucket_num来判断区间，以放入哪个桶。
 * 2. 桶的命名，不能命令成bucket1,bucket2这样傻乎乎的名字。可以用链表，也可以用用vector<vector<>>
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

template<class T>
void print_vector(vector<T> &v){
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

/**
 * 下面的桶排序，不具有通用性，仅仅针对输入数据[0,1)的正态分布
 * 假定有10个桶，按照小数点后第一位来判断放入哪个桶
 * 0.09 放入第一个桶
 * 0.15 放入第二个桶
*/
void bucket_sort(vector<double> &v){
    int v_len = v.size();
    vector<vector<double>> buckets;
    buckets.resize(10);
    // if(buckets[9].empty()) // 测试下这样创建二维空向量行不行，哈哈，阔以
    //     cout<<buckets.size()<<endl;

    for(int i=0; i<v_len; i++) // 把根据数据大小，把数据放在不同的桶里
        buckets[v[i]*10/10].push_back(v[i]);
    for(int i=0; i<10; i++) // 对每一个非空桶按照升序排序
        if(!buckets[i].empty())
            sort(buckets[i].begin(),buckets[i].end());
    int k=0;
    for(int i=0; i<10; i++) // 把每一个桶中的内容按顺序放回原向量
        if(!buckets[i].empty()){
            for(int j=0; j<buckets[i].size(); j++){
                v[k]=buckets[i][j];
                k++;
            }
        }
    
    return;
}

int main(void){
    // 创建nums个[0,1)随机数
    int nums = 10;
    vector<double> v(nums,0);
    srand(time(NULL));
    for(int i=0; i<nums; i++)
        v[i]=rand()%100/100.0;//
    cout<<"随机创建"<<nums<<"个随机数"<<":";
    print_vector<double>(v);

    bucket_sort(v);
    cout<<"桶排序之后元素输出:";
    print_vector<double>(v);
    return 0;
}