//在kmp.cpp的基础上，优化下，程序结构
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void get_next(const string & s,vector<int> &max_fix);
int kmp_search(const string &ori,const string & ser,vector<int> &next);

void get_next(const string & s,vector<int> &max_fix)
{
    int i=1;
    max_fix[0]=0;
    int k=0;
    while (i<s.length())
    {
        if(s[i]==s[k])
        {
            k++;
            max_fix[i]=k;
            i++;
        }
        else
        {
            if(k==0)  //（向前递归至）与第一个进行比较，不相等
            {
                max_fix[i]=0;//与第一个都不相等，长度为0
                i++;
            }  
            else
                k=max_fix[k-1];//向前递归;下标=长度-1   
        }       
    } 

    for(unsigned i=max_fix.size()-1;i>0;i--)
        max_fix[i]=max_fix[i-1];
    max_fix[0]=-1;
}


int kmp_search(const string &ori,const string & ser)
{
    vector<int> next(ser.length(),0);
    get_next(ser,next);

    int i=0,j=0;
    int ori_len=(int)ori.length(),ser_len=(int)ser.length();//强制转换下
    while (i<ori_len && j<ser_len)
    {
        if(j == -1 || ori[i]==ser[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if(j==ser.length())
        return i-j;
    else
        return -1;
}

int main(void)
{
    string ser="aaaab";
    string ori="aabaaaab";

    int loc=kmp_search(ori,ser);
    cout<<loc<<endl;
    return 0;
}