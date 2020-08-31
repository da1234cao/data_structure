/*题目：一元多项式的相加
分析：存储数据结构：系数+指数
方法一：用pair来存储系数和指数。pair存放在list中。
方法二：用map来存储。map<指数，系数> 自动排序。
输入结束标志 0 0；
*/


#include<iostream>
#include<list>

using namespace std;

void CreatPolyn(list< pair<int,int> > &polyn);
void PrintPolyn(list< pair<int,int> > &polyn);
list< pair<int,int> >::iterator Find_expn_loc(list< pair<int,int> > &polyn,int expn);
void AddPolyn(const list< pair<int,int> > &polyn1,const list< pair<int,int> > &polyn2,list< pair<int,int> > &ans_polyn);


int main(void)
{
    pair<int,int> elem;
    list< pair<int,int> > polyn1,polyn2,ans_polyn;
    
    CreatPolyn(polyn1);
    // PrintPolyn(polyn1);
    CreatPolyn(polyn2);
    // PrintPolyn(polyn2);
    AddPolyn(polyn1,polyn2,ans_polyn);
    PrintPolyn(ans_polyn);

    return 0;
}

void CreatPolyn(list< pair<int,int> > &polyn)
{
    int coef,expn;//系数和指数
    while(cin>>coef>>expn)
    {
        if( coef==0 && expn==0 )
            break;
        polyn.push_back(pair<int,int>(coef,expn));
    }
}

void PrintPolyn(list< pair<int,int> > &polyn)
{
    for(auto tmp : polyn)
        cout<<tmp.first<<"X^"<<tmp.second<<" ";
    cout<<endl;
}

list< pair<int,int> >::iterator Find_expn_loc(list< pair<int,int> > &polyn,int expn)
{
    for(auto it=polyn.begin();it!=polyn.end();it++)
    {
        if(it->first<=expn)
            return it;
    }
    return polyn.end();
}

void AddPolyn(const list< pair<int,int> > &polyn1,const list< pair<int,int> > &polyn2,list< pair<int,int> > &ans_polyn)
{
    auto elem1=polyn1.begin(),elem2=polyn2.begin();
    pair<int,int> elem3;
    while( elem1!=polyn1.end()&&elem2!=polyn2.end() )
    {
        if(elem1->second==elem2->second)
        {
            elem3.first=elem1->first+elem2->first;
            elem3.second=elem1->second;
            // auto loc=Find_expn_loc(ans_polyn,elem3.second);
            // if(loc != ans_polyn.end())
            // {
            //     if(elem3.second==loc->second)
            //         loc->first += elem3.first;
            //     else
            //         ans_polyn.insert(loc,elem3);
            // }
            // else 
            //     ans_polyn.push_back(elem3); 
            elem1++;  
            elem2++;     
        }
        else if(elem1->second < elem2->second)
        {
            elem3.first=elem1->first;
            elem3.second=elem1->second;
            elem1++;  
        }
        else
        {
            elem3.first=elem2->first;
            elem3.second=elem2->second;
            elem2++;     
        }
        ans_polyn.push_back(elem3);     
    }
    while(elem1!=polyn1.end()) 
    {
        elem3=*elem1;
        ans_polyn.push_back(elem3);
        elem1++;
    }   
    while (elem2!=polyn2.end())
    {
        elem3=*elem2;
        ans_polyn.push_back(elem3);
        elem2++;
    }     
}