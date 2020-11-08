/**
 * 大顶堆头文件
*/

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <vector>
using namespace std;

// 我刚开始写的时候，没有使用end
// end用map.size代替，使得被删除的节点被使用
void max_heapify(vector<int> &map, int node, const int end){
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
        max_heapify(map,maxloc,end);
    }
}

// end是要排序的堆的最后一个元素的下标
void buid_max_heap(vector<int> &map,const int end){
    int last_parent = (end-1)/2;
    for(int i=last_parent; i>=0; i--)
        max_heapify(map,i,end);
}

void max_heap_sort(vector<int> &map){
    int end = map.size()-1;
    buid_max_heap(map,end);
    for(end; end>=1;){ 
        swap(map[0],map[end]); //将最大值(根)与最后一位交换
        end--; // 删除最后一个
        buid_max_heap(map,end); // 重新构建大顶堆
    } //最后加上循环，得到所有元素排序
}

void print_max_heap(const vector<int> &map){
    int len = map.size();
    for(int i=0; i<len; i++)
        cout<<map[i]<<" ";
    cout<<endl;
}

#endif