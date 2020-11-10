/**
 * 第i小问题
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int partion(vector<int> &v,int low,int high);
int random_partion(vector<int> &v,int start,int end);
int random_select(vector<int> &v,int p,int q,int i);

template<class T>
void print_vector(vector<T> &v){
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

// 在[p,q]区间内找第i小的数字
int random_select(vector<int> &v,int p,int q,int i){
    if(p==q)
        return v[p];
    int r = random_partion(v,0,v.size()-1);
    int k = r-p+1; // 第i小的数字在划分后的左边还是右边
    if(i==k)
        return v[r];
    if(i<k)
        return random_select(v,p,r-1,i);//在左边找
    else 
        return random_select(v,r+1,q,i-k);//在右边找，丢弃左边的内容
}


// 快速排序的随机划分
int random_partion(vector<int> &v,int start,int end){
    srand(time(NULL));
    int random_loc = start + rand()%(end-start+1);
    swap(v[random_loc],v[0]);
    return partion(v,start,end);
}

// 快速排序划分
int partion(vector<int> &v,int low,int high){
    int pivot = v[low];// 初始化，把low的位置挖空出来，作为哨兵
    while(low<high){
        while(low<high && v[high]>=pivot)
            high--;
        v[low]=v[high];//可能是遇到小于pivot的内容了，把它放在左边，把high空出来；也可能是low=high，相同赋值下不影响;
        while(low<high && v[low]<=pivot)
            low++;
        v[high]=v[low];
    }
    v[low]=pivot;
    return low;
}

int main(void){
    vector<int> v={16,4,10,14,7,9,3,2,8,1};
    int i_small = 8;
    int ans = random_select(v,0,v.size()-1,i_small);
    sort(v.begin(),v.end());
    if(ans == v[i_small-1])
        printf("find the fisrt little %d num, is %d\n",i_small,ans);
    else
        cout<<"代码哪里有问题/没找到第i小元素"<<endl;
    return 0;
}