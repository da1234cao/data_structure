/**
 * 测试maximum_priority_queue.h头文件
*/

#include <iostream>
#include <vector>
#include "maximum_priority_queue.h"

using namespace std;

int main(void){
    vector<int> heap = {16,4,10,14,7,9,3,2,8,1};
    MPQ<int> mpq;
    //测试堆排序
    cout<<"堆排序之前：";
    mpq.print_max_heap(heap);
    mpq.max_heap_sort(heap);
    cout<<"使用堆排序之后：";
    mpq.print_max_heap(heap);

    // 先构建成大顶堆
    mpq.build_max_heap(heap,heap.size()-1);

    // 最大值
    cout<<"堆最大值："<<mpq.heap_maxnum(heap)<<endl;

    // 提取并删除最大值
    cout<<"提取并删除最大值："<<mpq.heap_extract_max(heap)<<endl;
    cout<<"提取并删除最大值之后：";
    mpq.print_max_heap(heap);

    // 增大一个元素
    mpq.heap_increase_key(heap,heap.size()-1,heap[heap.size()-1]+20);
    cout<<"堆最后一个元素增加20之后：";
    mpq.print_max_heap(heap);

    // 最后插入一个元素
    mpq.heap_insert(heap,15);
    cout<<"堆最后一个元素之后调整堆：";
    mpq.print_max_heap(heap);
    return 0;
}