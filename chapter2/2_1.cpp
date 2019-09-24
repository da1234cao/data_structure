#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void Print(list<int> li);
list<int>& Union(list<int> &La,const list<int> &Lb);

int main(void)
{
    list<int> La={1,3,5,7,9};
    list<int> Lb={2,4,6,8,9};
    Union (La,Lb);
    Print(La);
}

//算法2_1,合并两个线性表(如果想默认排序，不妨用set)
list<int>& Union(list<int> &La,const list<int> &Lb)
{
    for(auto tmp : Lb)
    {
        if( find(La.begin(),La.end(),tmp) == La.end() )
            La.push_back(tmp);
    }
    return La;
}

void Print(list<int> li)
{
    for(auto tmp : li)
        cout<<tmp<<" ";
    cout<<endl;
}