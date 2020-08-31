#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void Print(list<int> li);
list<int>& MergeList(const list<int> &La,const list<int> &Lb,list<int> &Lc);

int main(void)
{
    list<int> La={1,3,5,7,9,10};
    list<int> Lb={2,4,6,8,9};
    list<int> Lc; 
    MergeList (La,Lb,Lc);
    Print(Lc);
}

//将La和Lb合并，进入Lc。默认La，Lb,已经排序
//程序没有进行中间的插入删除，建议用vector;
list<int>& MergeList(const list<int> &La,const list<int> &Lb,list<int> &Lc)
{
    Lc.clear();
    auto i=La.begin(),j=Lb.begin();

    while ( i!=La.end()&&j!=Lb.end() )
    {
        if(*i<*j)
        {
            Lc.push_back(*i);
            i++;
        }
        else
        {
            Lc.push_back(*j);
            j++;
        } 
    }
    if(i==La.end())
        Lc.insert(Lc.end(),j,Lb.end());
    if(j==Lb.end())
        Lc.insert(Lc.end(),i,La.end());
    return Lc;
}

void Print(list<int> li)
{
    for(auto tmp : li)
        cout<<tmp<<" ";
    cout<<endl;
}