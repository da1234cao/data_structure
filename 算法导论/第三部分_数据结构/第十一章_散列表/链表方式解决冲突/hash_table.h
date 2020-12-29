/**
 * hash表
 * 参考代码：https://www.cnblogs.com/Anker/archive/2013/01/27/2879150.html
 * 实现：插入、删除、查找、rehash
*/
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<class T>
class HashTable{
private:
    vector<list<T>> hash_table;
    int currentSize;//当前hash表中元素个数
public:
    HashTable(int size=10);
    virtual int hash(const T &elem); // h(k)=k/m
    int insert(T &elem); // 插入
    void search(const T &elem,T &ans); // 查找
    int remove(const T &elem); // 删除hash表中元素
    void display(); // 打印整个哈希表
    int hash_string(const string &name); // 将字符串转换成数字
    int rehash(int size); // n/m超过阈值的时候，rehash
};

template<class T>
HashTable<T>::HashTable(int size){
    hash_table.resize(size);
    currentSize=0;
}

// 将字符串hash：使用除法散列法
// 字符的hash相加，取hashtable大小的mode
template<class T>
int HashTable<T>::hash_string(const string &name){
    int len = name.length();
    int sum=0;
    for(int i=0; i<len; i++)
        sum+=(int)name[i];
    return sum%hash_table.size();
}

// 继承这个类，重写这个方法
// 下面这个方法是针对employ类
template<class T>
int HashTable<T>::hash(const T &elem){
    return hash_string(elem.getname());
}

// 在hash表中插入元素
template<class T>
int HashTable<T>::insert(T &elem){
    list<T> &whichlist = hash_table[hash(elem)];
    if(find(whichlist.begin(),whichlist.end(),elem)!=whichlist.end())
        return 0; // hash表中已经存在，直接返回
    whichlist.push_back(elem);
    currentSize++;
    if(currentSize>hash_table.size()/2)//如果大于阈值，rehash
        rehash(2*hash_table.size());
    return 1;
}

// 通过hash查找元素
template<class T>
void HashTable<T>::search(const T &elem,T &ans){
    list<T> &whichlist = hash_table[hash(elem)];
    typename std::list<T>::iterator it;
    it=find(whichlist.begin(),whichlist.end(),elem);
    if(it!=whichlist.end())
        ans=*it;
}

// 删除hash表中某个元素
template<class T>
int HashTable<T>::remove(const T &elem){
    list<T> &whichlist = hash_table[hash(elem)];
    typename std::list<T>::iterator it;
    it=find(whichlist.begin(),whichlist.end(),elem);
    if(it!=whichlist.end()){
        whichlist.erase(it);
        currentSize--;
        return 1;
    }
    return 0;
}

// 打印整个hash表
template<class T>
void HashTable<T>::display(){
    int len = hash_table.size();
    for(int i=0; i<len; i++){
        typename std::list<T>::iterator it;
        list<T> &whichlist = hash_table[i];
        for(it=whichlist.begin(); it!=whichlist.end(); it++)
            cout<<*it;
    }
}

// 当元素/哈希表，到一定阈值的时候，rehash
template<class T>
int HashTable<T>::rehash(int size){
    vector<list<T>> old_hash_table;
    old_hash_table.assign(hash_table.begin(),hash_table.end());
    hash_table.resize(size);
    // hash_table.clear(); // 这个把大小清零
    for(int i=0; i<size; i++)
        hash_table[i].clear();
    for(int i=0; i<old_hash_table.size(); i++){
        typename std::list<T>::iterator it;
        list<T> &whichlist = old_hash_table[i];
        for(it=whichlist.begin(); it!=whichlist.end(); it++)
            insert(*it);
    }
}
#endif