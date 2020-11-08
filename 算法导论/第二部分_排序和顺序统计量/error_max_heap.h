/**
 * 大顶堆头文件
 * 这个是错误内容。我想写一个对数组内部进行堆排序的的max_heap函数
 * 但是这会违背下标索引，所以是错的。堆排序只能对所有所有内容进行排序。
 * 部分排序破坏了树的结构，即破坏了下标规律
*/

#ifndef ERROR_MAX_HEAP_H
#define ERROR_MAX_HEAP_H
#include <iostream>
#include <vector>
using namespace std;

/**
 * 下标start为根节点的子树，遵循大顶堆的性质。
 * 前提：start的左子树和右子树原本符合大顶堆
 * 索引为i的左孩子的索引是 (2*i+1);
 * 索引为i的右孩子的索引是 (2*i+2);
 * 索引为i的父结点的索引是 floor((i-1)/2);
 * */
void max_heapify(vector<int> &map, int node,const int start,const int end){
    // int lc = start<<1 + 1;
    int lc = node*2 + 1;
    int rc = node*2 + 2;
    int maxloc = node;
    if(lc<=end && map[lc]>map[maxloc])
        maxloc = lc;
    if(rc<=end && map[rc]>map[maxloc])
        maxloc = rc;
    if(maxloc!=node){
        swap(map[node],map[maxloc]);
        max_heapify(map,maxloc,start,end);
    }
}


void buid_max_heap(vector<int> &map,const int start,const int end){
    int last_parent = (end-start+1-1)/2+start;
    for(int i=last_parent; i>=start; i--)
        max_heapify(map,i,start,end);
}

void max_heap_sort(vector<int> &map,int start,int end){
    int len = end-start+1;
    buid_max_heap(map,start,end);
    for(int i=len; i>=1; i--){ 
        swap(map[start],map[end]); //将最大值(根)与最后一位交换
        end--; // 删除最后一位
        buid_max_heap(map,start,end); // 重新构建大顶堆
    } //最后加上循环，得到所有元素排序
}

void print_max_heap(const vector<int> &map,int start,int end){
    for(int i=start; i<end; i++)
        cout<<map[i]<<" ";
    cout<<endl;
}
#endif