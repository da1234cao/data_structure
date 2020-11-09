/**
 * 利用大顶堆实现最大优先队列：获取[删除]最大元素、插入元素
 * 写代码的时候想到一个问题：对象将数据和操作封装在一起。
 * 有时候数据要从外部传入，使用指针可以。
 * 类只封装方法，只有内部使用的数据放在private.
 * 使用外部的数据，使用引入传入
*/

#ifndef MAXIMUN_PRIORITY_QUEUE_H
#define MAXIMUN_PRIORITY_QUEUE_H

#include <vector>
using namespace std;

template<class T>
class MPQ{
    private:
        // //记录对象外面堆的大小
        // int heap_size; 
    
    public:
        // MPQ(const vector<T> &hp){
        //     heap_size = hp.size();
        // }
        // ~MPQ(){};
        void max_heapify(vector<T> &heap,int inode,const int end);
        void build_max_heap(vector<T> &heap,const int end);//构建大顶堆
        void max_heap_sort(vector<T> &heap);//大顶堆排序
        void print_max_heap(const vector<T> &heap);//打印堆

        T heap_maxnum(vector<T> &heap);//堆的最大值
        T heap_extract_max(vector<T> &heap);//返回堆的最大值，并删除最大值
        void heap_increase_key(vector<T> &heap,int i,T key);//将第ｉ个位置的值增大到key
        void heap_insert(vector<T> &heap,T key); //堆中插入一个元素
};

/**
 * 当前节点为根的树，左右子树满足堆条件，整体调整为堆
 * 索引为i的左孩子的索引是 (2*i+1);
 * 索引为i的右孩子的索引是 (2*i+2);
 * 索引为i的父结点的索引是 floor((i-1)/2);
*/
template<class T>
void MPQ<T>::max_heapify(vector<T> &heap,int inode,const int end){
    int lc = 2*inode+1;
    int rc = 2*inode+2;
    int maxloc = inode;
    if(lc<=end && heap[lc]>heap[maxloc])
        maxloc = lc;
    if(rc<=end && heap[rc]>heap[maxloc])
        maxloc = rc;
    if(maxloc!=inode){
        swap(heap[inode],heap[maxloc]);
        max_heapify(heap,maxloc,end);
    }
}

// 构建大顶堆
template<class T>
void MPQ<T>::build_max_heap(vector<T> &heap,const int end){
    int last_parent=(end-1)/2;
    for(int i=last_parent;i>=0;i--)
        max_heapify(heap,i,end);
}

// 大顶堆排序
template<class T>
void MPQ<T>::max_heap_sort(vector<T> &heap){
    int end = heap.size()-1;
    build_max_heap(heap,end);
    for(end;end>0;){
        swap(heap[0],heap[end]);//将最大值和最后一个元素互换
        end--;//删除最后一个元素
        max_heapify(heap,0,end);
    }
}

// 打印堆
template<class T>
void MPQ<T>::print_max_heap(const vector<T> &heap){
    int len = heap.size();
    for(int i=0; i< len; i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}

// 返回堆最大值
template<class T>
T MPQ<T>::heap_maxnum(vector<T> &heap){
    // build_max_heap(heap,heap.size()-1);//先构建成大顶堆
    return heap[0];
}

// 返回最大值，并删除
template<class T>
T MPQ<T>::heap_extract_max(vector<T> &heap){
    if(heap.size()<1)
        cout<<"heap underflow";
    // build_max_heap(heap,heap.size()-1);//先构建成大顶堆
    T max = heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();//删除最后一个元素
    max_heapify(heap,0,heap.size()-1);//重新构建成大顶堆
    return max;
}

//将第ｉ个位置的值增大到key
template<class T>
void MPQ<T>::heap_increase_key(vector<T> &heap,int i,T key){
    if(i>=heap.size() || heap[i]>=key){
        cout<<"heap increase i loc key error";
        return;
    }
    // build_max_heap(heap,heap.size()-1);//先建立成大顶堆
    heap[i]=key;
    while(i>0 && heap[i]>heap[(i-1)/2]){
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2;
    }
}
// 对中插入一个元素
/**
 * 书上的方法：在最后插入一个负无穷，然后调用上面的heap_increase_key
 * 问题在于，使用Ｔ,不知道是什么类型，没法使用INT_MIN这样的宏
 * 可以直接在最后插入一个数字，手动再次实现向上比较的过程
 * heapify是向下调整过程，heap_increase_key是向上调整过程
*/
template<class T>
void MPQ<T>::heap_insert(vector<T> &heap,T key){
    heap.push_back(key);
    int i=heap.size()-1;
    while(i>0 && heap[i]>heap[(i-1)/2]){
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2;
    }    
}
#endif