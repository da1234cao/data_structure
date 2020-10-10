/**
 * 归并排序
 * 参考：https://www.cnblogs.com/chengxiao/p/6194356.html
*/
#include <iostream>
#include <vector>
 
using namespace std;
 
void Merge_Sort(vector<int>& v,int start,int end);
void merge_sort(vector<int>& v,int left,int right,vector<int>& tmp);
void merge_sort_vector(vector<int>& v,int left,int mid,int right,vector<int>& tmp);
void printf_vector(const vector<int>& v);
 
int main(void){
    vector<int> v = {1,5,8,6,10,8,7,2,13};
    Merge_Sort(v,0,v.size()-1);
    printf_vector(v);
    return 0;
}
 
void printf_vector(const vector<int>& v){
    for(int i=0; i< v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
 
void Merge_Sort(vector<int>& v,int start,int end){
    vector<int> tmp(end-start+1);
    int left=start,right=end;
    merge_sort(v,left,right,tmp);
}
 
void merge_sort(vector<int>& v,int left,int right,vector<int>& tmp){
    if(left<right){
        int mid = (left+right)/2;
        merge_sort(v,left,mid,tmp);
        merge_sort(v,mid+1,right,tmp);
        merge_sort_vector(v,left,mid,right,tmp);
    }
}
 
void merge_sort_vector(vector<int>& v,int left,int mid,int right,vector<int>& tmp){
    //分治法中，合并有序向量
    int i=left,j=mid+1,t=0;
    while(i<=mid && j<=right){
        if(v[i]<v[j])
            tmp[t++]=v[i++];
        else
            tmp[t++]=v[j++];
    }
    while(i<=mid)
        tmp[t++]=v[i++];
    while(j<=right)
        tmp[t++]=v[j++];
    t=0;
    while(left<=right)
        v[left++]=tmp[t++];
}
 