/**
 * 基数排序
 * 我开始的时候，没有想出来，如何使用计数排序对每一位进行排序
 * 因为如果把每一位取出来排序，和原来的数字脱离了联系
 * 参考：https://www.cnblogs.com/skywang12345/p/3603669.html
 * 这个代码：在r=logn的时候，时间复杂度最小。关于这不实现。
*/

#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &v){
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

/**
 * 按照数组v的exp位进行计数排序
 * exp=1,按照个位排序
 * exp=10,按照十位排序
 * exp=100,按照百位排序
*/
void radix_couting_sort(vector<int> &v,int exp){
    int v_size = v.size();
    vector<int> output(v_size,0);
    vector<int> buckets(10,0);

    for(int i=0; i<v_size; i++)
        buckets[v[i]/exp%10]++;
    for(int i=1; i<buckets.size(); i++)
        buckets[i]+=buckets[i-1];
    // for(int i=0; i<v_size; i++){
    // 稳定排序，必须从后向前，因为相同数字的填充是向前填充的
    for(int i=v_size-1; i>=0; i--){
        output[buckets[v[i]/exp%10]-1]=v[i];
        buckets[v[i]/exp%10]--;
    }
    for(int i=0; i<v_size; i++)
        v[i]=output[i];
    return;
}

// 基数排序
void radix_sort(vector<int> &v){
    int max=v[0];
    for(int i=1; i<v.size(); i++)
        if(v[i]>max)
            max=v[i];
    for(int exp=1; max/exp>0; exp*=10)
        radix_couting_sort(v,exp);
    return;
}


int main(void){
    vector<int> v={16,4,10,14,7,9,3,2,8,1};

    cout<<"计数排序之前数组：";
    print_vector(v);
    radix_sort(v);
    cout<<"计数排序之后数组：";
    print_vector(v);

    return 0;
}