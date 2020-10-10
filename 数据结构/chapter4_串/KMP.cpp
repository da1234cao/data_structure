#include<iostream>
#include<string>
#include<vector>

using namespace std;

void get_max_fix(const string & s,vector<int> &max_fix);
void get_next(vector<int> &next);
int kmp_search(const string &ori,const string & ser,vector<int> &next);

void get_max_fix(const string & s,vector<int> &max_fix)
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
}

void get_next(vector<int> &next)
{
    for(unsigned i=next.size()-1;i>0;i--)
        next[i]=next[i-1];
    next[0]=-1;
}

int kmp_search(const string &ori,const string & ser,vector<int> &next)
{
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
    vector<int> next(ser.length(),0);
    get_max_fix(ser,next);
    get_next(next);
    for(auto i : next)
        cout<<i<<" ";
    cout<<endl;
    int loc=kmp_search(ori,ser,next);
    cout<<loc<<endl;
    return 0;
}