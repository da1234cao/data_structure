/*
#：前一个字符无效
@：之前的字符均无效
回车：清空栈（将字符送入数据区）
*/
#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>

using namespace std;

inline void DspalyLine(stack<char> &s);
inline void ClearStack(stack<char> &s);
void LineEdit();

int main(void)
{  
    if( freopen("3_2.txt","r",stdin)==NULL ) //不知道为甚：在调试状态，无法打开文件
    {
        cout<<"open file failed";
        exit(EXIT_FAILURE);
    }
    LineEdit();
    fclose(stdin);
    return 0;
}

//stack<int>().swap(s);这么写不知道行不行
inline void ClearStack(stack<char> &s)
{
    while(!s.empty())
        s.pop();
}

inline void Dspaly_And_Clear_Line(stack<char> &s)
{
    string str;
    stack<char> dispaly_stack;
    while (!s.empty())
    {
        dispaly_stack.push(s.top());
        s.pop();
    }
    while(!dispaly_stack.empty())
    {
        str.push_back(dispaly_stack.top());
        dispaly_stack.pop();
    }
    cout<<str<<endl;
}

void LineEdit()
{
    stack<char> s;
    int ch;
    ch=getchar();
    while (ch!=EOF)  //整体循环读取
    {
        while(ch!=EOF && ch!='\n')
        {
            switch (ch)
            {
            case '#':s.pop();break;
            case '@':ClearStack(s);break;
            default :s.push(ch);
            }
            ch=getchar();
        }
        Dspaly_And_Clear_Line(s);
        //ClearStack(s);
        if(ch!=EOF)
            ch=getchar();
    }
}