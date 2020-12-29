/**
 * 是开放寻址方法的hash表的增删查
 * 下面魔改下代码0.2版本
 * 
 * hash表使用vector形式，存储单元为pair；
 * pair中包含两部分：元素的状态，元素本身；
 * 使用元素中的某个属性作为关键字。
 * 
 * 参考：
 * c++模板类在继承中子类无法访问父类的成员：https://blog.csdn.net/sb985/article/details/79670881
*/
#ifndef HASH_TABLE_SEARCH_H
#define HASH_TABLE_SEARCH_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

template<class T>
class HashTable{
public:
    // HashTable(int size=20);
    virtual int hash(const T &elem,int i); // h(k)=k/m
    int insert(T &elem); // 插入
    int search(const T &elem); // 查找
    int remove(const T &elem); // 删除hash表中元素
    void display(); // 打印整个哈希表
    int hash_string(const string &name); // 将字符串转换成数字
private:
    enum statu {exist,del,nul};//标志位:exist存在表中;del被删除；nul空;
    vector< pair<statu,T> > hash_table;
};

// template<class T>
// HashTable<T>::HashTable(int size){
//     hash_table.resize(size);
//     for(int i=0; i<size; i++)
//         hash_table[i].first = nul;
// }

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
// 这里采用了线性查找
// h(k,i)=(h'(k)+i) mod m。这导致无法动态添加hash表大小
// 整个对象存在表中。将对象中的某个元素作为键值。
template<class T>
int HashTable<T>::hash(const T &elem,int i){
    // return (hash_string(elem.getid()) + i)%hash_table.size();
    return 0;
}

// 在hash表中插入元素
template<class T>
int HashTable<T>::insert(T &elem){
    int i,j;
    for(i=0; i<hash_table.size();i++){
        j=hash(elem,i);
        if(hash_table[j].first == nul || hash_table[j].first == del){ // 找见位置，插入
            hash_table[j].second = elem;
            hash_table[j].first = exist;
            break;
        }
        else if(!(hash_table[j].second == elem)){ // 位置被占，往后找
            i++;
            continue;
        }
    }
    if(i==hash_table.size()){
        cout<<"insert error;\n";
        return -1;
    }else
        return j;
}

// 通过hash查找元素
template<class T>
int HashTable<T>::search(const T &elem){
    int i,j;
    for(i=0; i<hash_table.size(); i++){
        j = hash(elem,i);
        if(hash_table[j].second==elem)//直接找见
            return j;
        if(hash_table[j].first == nul)
            return -1; //没有这个元素
        i++; // 位置被占，往后找
        continue;
    }
    return -1; //程序正常是运行不到这里的
}

// 删除hash表中某个元素
template<class T>
int HashTable<T>::remove(const T &elem){
    int loc = search(elem);
    if(loc == -1)
        return -1;
    hash_table[loc].first = del;
}

// 打印整个hash表
template<class T>
void HashTable<T>::display(){
    int len = hash_table.size();
    for(int i=0; i<len; i++){
        if(hash_table[i].first == exist)
            cout<<hash_table[i].second<<endl;
    }
}

#endif