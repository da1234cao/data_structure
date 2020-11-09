/**
 * 计数排序:只能排序较小的自然数
*/

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &v){
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

// 计数排序:参数A为待排序数组，参数B是存储A已排序数组
void couting_sort(const vector<int> &A,vector<int> &B){
    // 打擂台得出待排序数组的最大值
    int max=A[0];
    for(int i=1; i<A.size(); i++)
        if(A[i]>max)
            max=A[i];
    
    vector<int> C(max+1,0);// 开辟max+1个大小的临时数组

    for(int i=0; i<A.size(); i++)// 记录每个数字出现的次数，其中下标为数字本身
        C[A[i]]++;
    print_vector(C);
    for(int i=1; i<C.size(); i++)// 计算前缀和，C数组中的数字表示小于等于当前数的个数
        C[i]+=C[i-1];
    print_vector(C);
    for(int i=0; i<A.size(); i++){
        B[C[A[i]]-1]=A[i];// A根据C中小于等于当前数的个数，把元素放在B中合适的位置
        C[A[i]]--;// 由于可能出现相同的元素，相同的元素存放在B中对应位置的前一个位置
    }
    print_vector(B);
    return;
}


int main(void){
    vector<int> A={16,4,10,14,7,9,3,2,8,1};
    vector<int> B(A.size(),0);

    couting_sort(A,B);

    cout<<"计数排序之前数组：";
    print_vector(A);
    cout<<"计数排序之后数组：";
    print_vector(B);

    return 0;
}