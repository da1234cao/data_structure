/*
算法4.1
字符串查找
*/

#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    string ori="abcdefgdef";
    string ser="def";
    unsigned loc;
    loc=ori.find(ser,0);
    cout<<loc<<endl;

    return 0;
}
