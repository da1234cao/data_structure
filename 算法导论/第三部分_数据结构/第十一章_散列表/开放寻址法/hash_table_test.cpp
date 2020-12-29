/**
 * 测试hash_table.h
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



int main(void){
    cout<<"初始化插入数据"<<endl;
    Student st1("S201000913","张三");
    Student st2("S201000918","李四");
    Student st3("S201000920","王二");

    // 与其说是插入，不如说是复制;初始化hash表大小为10
    HashTable<Student> hashtable(10);
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
    ans = hashtable.search(st3);
    if(ans >= 0)
        cout<<"Ah,I find it~\n"<<ans;
    
    cout<<"hash表中删除元素："<<endl;
    hashtable.remove(st1);
    hashtable.display();

    return 0;
}