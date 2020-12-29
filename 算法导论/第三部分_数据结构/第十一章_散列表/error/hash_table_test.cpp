/**
 * 测试hash_table.h
 * 问题在于：
 * 1. 使用模板，子类中看不到父类方法。可以使用this护着类名:: 方式访问。
 * 2. C++中该如何设计类之间的继承。包括，父类和子类之间的成员变量；父类的成员函数在子类中的使用。
*/

#include <iostream>
#include <vector>
#include "hash_table_search.h"

using namespace std;

class Student{
private:
    string name="";
    string id="";
public:
    Student(){}
    Student(string id,string name):id(id),name(name){}
    const string & getid() const { return id;}
    const string & getname() const { return name;}
    bool operator == (const Student& st){
        return (id == st.getid())&&(name == st.getname()); 
    }
    void operator = (const Student& st){
        name = st.getname();
        id = st.getid(); 
    }
    friend ostream& operator <<(ostream &out, const Student &st){
        out<<"id:"<<st.getid()<<";name:"<<st.getname();
    }
};


template<class T>
class hash_table_search_student:public HashTable<T>{
private:
    enum statu {exist,del,nul};//标志位:exist存在表中;del被删除；nul空;
    vector< pair<statu,T> > hash_table;
public:
    // 初始化基类需要透传参数至基类的各个构造函数
    hash_table_search_student(int size=20){
        hash_table.resize(size);
        for(int i=0; i<size; i++)
            hash_table[i].first = nul;
    }
    int hash(string id,int i){
        return (HashTable<T>::hash_string(id) + i)%hash_table.size();
    }
    int insert(string id,string name){
        Student st(id,name);
        HashTable<T>::insert(st);
    }
    // int insert(Student &st){
    //     HashTable<T>::insert(st);
    // }
    int search(string id){
        int i,j;
        for(i=0; i<hash_table.size();i++){
            j=hash(id,i);
            if(hash_table[j].second.getid() == id)
                return j;
            if(hash_table[j].first == nul)
                return -1;
            i++; // 位置被占，往后找
            continue;
        }
        return -1; //程序正常是运行不到这里的
    }
    int remove(string id){
        int loc = search(id);
        HashTable<T>::remove(hash_table[loc].second);
    }
};


/******************上面构建两个测试用的类********************************/

int main(void){
    cout<<"初始化插入数据"<<endl;
    Student st1("S201000913","张三");
    Student st2("S201000918","李四");
    Student st3("S201000920","王二");

    // 与其说是插入，不如说是复制;初始化hash表大小为10
    hash_table_search_student<Student> hashtable(10);
    hashtable.insert(st1);
    hashtable.insert(st2);
    hashtable.insert(st3);
    cout<<"hash表中所有元素："<<endl;
    hashtable.display();

    // 查找
    // 这里通过一个元素查找，而非通过学号查找姓名
    // 通过序号查找姓名
    cout<<"hash表中查找元素：";
    int ans;
    ans = hashtable.search("S201000913");
    if(ans >= 0)
        cout<<"Ah,I find it~\n"<<ans;
    
    cout<<"hash表中删除元素："<<endl;
    hashtable.remove("S201000913");
    hashtable.display();

    return 0;
}