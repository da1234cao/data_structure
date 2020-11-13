/**
 * 测试hash_table.h
*/

#include <iostream>
#include <vector>
#include "hash_table.h"

using namespace std;

class employee{
private:
    string name="";
    int salary;
public:
    employee(){}
    employee(string name,int salary):name(name),salary(salary){}
    const string & getname() const { return name;}
    const int & getsalary() const { return salary;}
    bool operator == (const employee& ee){
        return name == ee.getname();
    }
    void operator = (const employee& ee){
        name = ee.getname();
        salary = ee.getsalary(); 
    }
    friend ostream& operator <<(ostream &out, const employee &ee){
        out<<"name:"<<ee.getname()<<";salary:"<<ee.getsalary()<<endl;
    }
};

int main(void){
    employee ee1("tom",6000);
    employee ee2("jerry",7000);
    employee ee3("BoB",6500);

    HashTable<employee> hashtable(10);
    hashtable.insert(ee1);
    hashtable.insert(ee2);
    hashtable.insert(ee3);
    cout<<"hash表中所有元素："<<endl;
    hashtable.display();

    // 下面是通过整体查找
    // 通过名字查找工资的方式，没有实现。可以继承重载search函数
    cout<<"hash表中查找元素：";
    employee ans;
    hashtable.search(ee1,ans);
    if(!ans.getname().empty())
        cout<<"Ah,I find it~   "<<ans;
    
    cout<<"hash表中删除元素："<<endl;
    hashtable.remove(ee1);
    hashtable.display();

    return 0;
}