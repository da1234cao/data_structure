/**
 * 描述：完成插入排序的生序/降序过程
 * 缺点：
 * 1. 我暂时没有去看模板怎么写，暂定向量元素类型为float；
 * 2. 不能像sort函数那样，写一个比较函数。
 * 3. 没有测试单元
*/
#include <iostream>
#include <vector>

using namespace std;

void descendInsertSort(vector<float>& v);
void ascendInsertSort(vector<float>& v);
void printVector(vector<float>& v);

int main(void){
    vector<float> v={1,5,8,9,2,4,7,10};
    printVector(v);
    descendInsertSort(v);
    printVector(v);

    printVector(v);
    ascendInsertSort(v);
    printVector(v);
    return 0;
}

/**打印向量*/
void printVector(vector<float>& v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

/**升序插入排序*/
void ascendInsertSort(vector<float>& v){
    //空向量，包含一个元素的向量，直接返回
    if(v.size() < 2)
        return;
    
    int i,j,key;
    for(j=1; j<v.size(); j++){
        key = v[j];
        for(i=j-1; i>=0; i--){
            if(v[i] > key)
                v[i+1]=v[i];
            else
               break; //break可以调整到循环里面
        }
        v[i+1]=key;
    }
}

/**降序插入排序*/
void descendInsertSort(vector<float>& v){
    //空向量，包含一个元素的向量，直接返回
    if(v.size() < 2)
        return;
    
    int i,j,key;
    for(j=1; j<v.size(); j++){
        key = v[j];
        for(i=j-1; i>=0; i--){
            if(v[i] < key)
                v[i+1]=v[i];
            else{
            //    v[i+1]=key; 不能放在里面，因为第一个也可能移位
               break; 
            } 
        }
         v[i+1]=key;
    }

}