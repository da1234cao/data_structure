/*题目：一元多项式相乘
多项式A：1+2*x-4*x^4
多项式B：2-2*x+5^x^4
输入：
0 1 2 1 -4 4 0 0
2 0 -2 1 5 4 0 0
输出：
2+2*x+13*x^5+20*x^8
方法：多项式相加，我们用了list<pair<int,int>>.这次用map<指数,系数>
*/

#include<iostream>
#include<map>

using namespace std;

void get_polyn(map<int,int> &polyn);
void print_polyn(map<int,int> &polyn);
void multiply_polyn(const map<int,int> &polyn1,const map<int,int> &polyn2,map<int,int> &ans_polyn);

int main(void)
{
    map<int,int> polyn1,polyn2,ans_polyn;
    get_polyn(polyn1);
    print_polyn(polyn1);
    get_polyn(polyn2);
    print_polyn(polyn2);
    multiply_polyn(polyn1,polyn2,ans_polyn);
    print_polyn(ans_polyn);
    return 0;
}

void get_polyn(map<int,int> &polyn)
{
    int coef,expn;  //系数，指数
    while(cin>>coef>>expn)
    {
        if( coef==0&&expn==0 )
            break;
        polyn[expn]=coef;
    }
}

void print_polyn(map<int,int> &polyn)
{
    for(auto tmp : polyn)
        cout<<"+"<<tmp.second<<"*X^"<<tmp.first;
    cout<<endl;
}

void multiply_polyn(const map<int,int> &polyn1,const map<int,int> &polyn2,map<int,int> &ans_polyn)
{
    ans_polyn.clear();
    pair<int,int> elem3;
    for( auto elem1:polyn1)
    {
        for(auto elem2:polyn2)
        {
            elem3.first=elem1.first+elem2.first;
            elem3.second=elem1.second*elem2.second;
            ans_polyn[elem3.first]+=elem3.second;
        }
    }
}