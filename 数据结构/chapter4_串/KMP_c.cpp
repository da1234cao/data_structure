/*
KMP.cpp程序结构还行，但还有两点可以优化
+ next数组右移过程，可以省略
+ next数组本身的游湖，在子next中，禁止本身相同。
    eg：aaaab 的next数组不是 -1 0 1 2 3；而是 -1 -1 -1 -1  0

    下面的问题是：已知next [0, ..., j]，如何求出next [j + 1]呢
    对于P的前j+1个序列字符：
    若p[k] == p[j]，则next[j + 1 ] = next [j] + 1 = k + 1；
    若p[k ] ≠ p[j]，如果此时p[ next[k] ] == p[j ]，则next[ j + 1 ] =  next[k] + 1，
        否则继续递归前缀索引k = next[k]，而后重复此过程。 
        相当于在字符p[j+1]之前不存在长度为k+1的前缀"p0 p1, …, pk-1 pk"跟后缀“pj-k pj-k+1, …, pj-1 pj"相等，
        那么是否可能存在另一个值t+1 < k+1，使得长度更小的前缀 “p0 p1, …, pt-1 pt” 等于
        长度更小的后缀 “pj-t pj-t+1, …, pj-1 pj” 呢？如果存在，
        那么这个t+1 便是next[ j+1]的值，此相当于利用已经求得的next 数组（next [0, ..., k, ..., j]）
        进行P串前缀跟P串后缀的匹配。

主要修改get_next函数。
直接求next(真前缀)。与 最大前后缀右移的关系。 
*/

//复杂，不看答案，我也再次写不出来，这个程序。还是没有理解透彻这种优化思想
//但是kmp_b.cpp中，思路简单好些。当然，比这个程序慢点。

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void get_next(const string & s,vector<int> &next);
int kmp_search(const string &ori,const string & ser,vector<int> &next);

void get_next(const string & s,vector<int> &next)
{
	next[0] = -1;
	int k = -1;
	int j = 0;
    int s_len=(int)s.length();
	while (j < s_len - 1)
	{
		//p[k]表示前缀，s[j]表示后缀  
		if (k == -1 || s[j] == s[k])  //k=-1的情况有点复杂
		{
			++j;  //真前缀
			++k;
		
			if (s[j] != s[k]) 
				next[j] = k;   
			else
				//因为不能出现s[j] = s[ next[j ]].由前向后，不需要递归
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
    for(auto i: next)
        cout<<i<<" ";
    cout<<endl; 
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
    string ser="agcagc";
    string ori="bbaagctagcagctagctd";

    int loc=kmp_search(ori,ser);
    cout<<loc<<endl;
    return 0;
}