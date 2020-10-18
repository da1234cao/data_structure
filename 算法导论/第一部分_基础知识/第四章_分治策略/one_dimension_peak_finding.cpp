/**
 * 描述：一维数组的峰值查找,找到其中一个峰值就好
 * 峰值：元素不小于左边或者右边的元素，a[i-1]<=a[i]>=a[i-1]
 * 默认：a[-1]=负无穷，a[n]=负无穷，所以峰值必然存在
 * 
 * 方法一：暴力法，从左向右遍历
 * 方法二：分治法；
 * 如果a[mid-1]<=a[mid]>=a[mid]，直接找见峰值;
 * 如果a[mid-1]>=a[mid]，则递推地在左边部分进行查找；
 * 如果a[mid]<=a[mid+1]，则递推地在右边部分进行查找；
 * 
 * writer:dacao
 * write_time:2020/10/18
 * GPL
*/

#include <iostream>
#include <vector>
#include <utility>
// #include <csetjmp>

using namespace std;

void findPeak1(const vector<int>& mountain,pair<int,int>& peak);
void findPeak2(const vector<int>& mountain,pair<int,int>& peak,int left,int right);
void FindPeak(const vector<int>& mountain,pair<int,int>& peak,int mod);

// jmp_buf jmpbuffer;

int main(void){
    vector<int> mountain = {1,8,9,5,4,6,2,1};
    pair<int,int> peak; //用来记录peak的下标与高度

    // FindPeak(mountain,peak,1);
    FindPeak(mountain,peak,2);
    cout<<"peak location is "<<peak.first<<endl;
    cout<<"peak high is "<<peak.second<<endl;

    return 0;
}

void FindPeak(const vector<int>& mountain,pair<int,int>& peak,int mod){
    // mod=1,方法一，暴力遍历法；mod=2,方法二，分治法。

    // 预处理:长度未0,1判断，峰值在第一个，最后一个判断
    int length = mountain.size(); //long unsigned int
    if(length==0){
        cout<<"当前向量未空，不存在峰值..."<<endl;
        exit(0);
    }
    if(length==1 || (mountain[0]>=mountain[1])){
        peak.first=0;
        peak.second=mountain[0];
        return;
    }
    if(mountain[length-2]<=mountain[length-1]){
        peak.first=length-1;
        peak.second=mountain[length-1];
        return;
    }

    // 根据mod，选择处理方法
    if(mod==1)
        findPeak1(mountain,peak);
    else if(mod==2){
        // setjmp(jmpbuffer);
        findPeak2(mountain,peak,0,mountain.size()-1);
    }else{
        cout<<"no such mod..."<<endl;
        exit(0);
    }
    
}



void findPeak2(const vector<int>& mountain,pair<int,int>& peak,int left,int right){
    int mid = (left+right)>>1;
    if((mountain[mid-1]<=mountain[mid]) && (mountain[mid]>=mountain[mid+1])){
        peak.first = mid;
        peak.second = mountain[mid];
        // 无法直接跳出递归
        // longjmp(jmpbuffer,1);//暂时不知道为啥用不了这个函数，提示无法解析setjmp.S
    }else if(mountain[mid-1]>=mountain[mid])
        findPeak2(mountain,peak,left,mid);
    else
        findPeak2(mountain,peak,mid+1,right);
}




void findPeak1(const vector<int>& mountain,pair<int,int>& peak){
    // 方法一：暴力法。a[i-1]<=a[i]>=a[i-1]
    int length = mountain.size(); //long unsigned int

    // // 长度未0,1判断，峰值在第一个，最后一个判断
    // if(length==0){
    //     cout<<"当前向量未空，不存在峰值..."<<endl;
    //     exit(0);
    // }
    // if(length==1 || (mountain[0]>=mountain[1])){
    //     peak.first=0;
    //     peak.second=mountain[0];
    //     return;
    // }
    // if(mountain[length-2]<=mountain[length-1]){
    //     peak.first=length-1;
    //     peak.second=mountain[length-1];
    //     return;
    // }

    for(int i=1; i<length-1;i++){
        if((mountain[i-1]<=mountain[i]) && (mountain[i]>=mountain[i+1])){
            peak.first=i;
            peak.second=mountain[i];
            return;
        }
    }

    return;
}