/*
用栈实现：数值转换
输入：三个整数a，n，b。a表示其后的n 是a进制整数，b表示欲将a进制整数n转换成b进制整数。
      a，b是十进制整数，2 =< a，b <= 16。
输出：包含一行，该行有一个整数为转换后的b进制数。输出时字母符号全部用大写表示，
     即（0，1，...，9，A，B，...，F）。
参考链接：
十进制数转换成十六进制数：https://blog.csdn.net/sinat_38816924/article/details/78440502
通过栈实现进制的转换：https://blog.csdn.net/sinat_38816924/article/details/79235032
任意两个不同进制非负整数的转换：https://blog.csdn.net/sinat_38816924/article/details/81435415
*/
#include<iostream>
#include<stack>
#include<string>
#include<cctype>

using namespace std;

string Convert(int a,string n,int b);


int main(void)
{
    int a,b;
    string n,convert_n;  //十六进制数包含字母，所以我需要string
    while(cin>>a>>n>>b)
    {
        convert_n=Convert(a,n,b);
        cout<<convert_n<<endl;
    }
    return 0;
}



string Convert(int a,string n,int b)
{
    //先把字符串转换成小写，然后转换成对应的十进制数字
    int ten_decimal_ans=0;
    for(auto &ch : n)
    {
        ch=tolower(ch);
        if(isdigit(ch))  
            ten_decimal_ans=ten_decimal_ans*a+(ch-'0');
        else if(isalpha(ch))
            ten_decimal_ans=ten_decimal_ans*a+(ch-'a'+10);
        else
            exit(EXIT_FAILURE);//简单起见，咱们不抓取错误，直接退出
    }
    //把十进制数转换成b进制数的字符串
    stack<char> s;
    string b_decimal_ans;
    int tmp;
    if(ten_decimal_ans==0)//补上这个
        s.push(0+'0');
    while(ten_decimal_ans)
    {
        tmp=ten_decimal_ans%b;
        if(tmp<10)
            s.push(tmp+'0');
        else if(tmp<16)
            s.push(tmp+'A');
        else
            exit(EXIT_FAILURE);
        ten_decimal_ans/=b;
    }
    while (!s.empty())
    {
        b_decimal_ans.push_back(s.top());
        s.pop();
    }
    
    return b_decimal_ans;
}