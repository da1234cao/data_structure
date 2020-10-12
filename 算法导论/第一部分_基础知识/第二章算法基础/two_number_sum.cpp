/**
 * 题目：
 * 给定n个元素的集合S和整数x
 * 判断集合中，是否有两个元素的和为x
 * 注：集合，自然其中不会有重复的元素
 * 
 * 要求：
 * 时间复杂度为nlogn
 * 
 * 方法零：暴力法，略
 * 
 * 方法一：
 * 使用归并排序。排序之后，从首尾向中间查找;
 * 方法正确性的证明，我不会。感觉是对的。就像拨游码一样，每次的修改总是最小的
 * 时间复杂度：nlogn
 * 
 * 方法二：利用map，将缺少的部分放在map中。查看是否存在元素整哈等于差值的。
 * 时间复杂度：n
*/

#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

void Merge_Sort(vector<int>& v,int start,int end);
void merge_sort(vector<int>& v,int left,int right,vector<int>& tmp);
void merge_sort_vector(vector<int>& v,int left,int mid,int right,vector<int>& tmp);
void printf_vector(const vector<int>& v);

bool two_number_sum1(vector<int>& v, int sum,pair<int,int>& ans);
bool two_number_sum2(vector<int>& v, int sum, pair<int,int>& ans);

int main(void){
    vector<int> v ={3,41,52,26,38,57,9,49};
    int sum = v[3]+v[5];
    pair<int,int> ans;//用来存储结果[下标 or 元素内容][两种方法存储的形式不同]

    // if(two_number_sum1(v,sum,ans))
    //     printf("%d equl to element %d add element %d\n",sum,v[ans.first],v[ans.second]);
    // else
    //     printf("There are not two Numbers here, the sum of which are %d\n",sum);

    
    if(two_number_sum2(v,sum,ans))
        printf("%d equl to element %d add element %d\n",sum,ans.first,ans.second);
    else
        printf("There are not two Numbers here, the sum of which are %d\n",sum);
    
    return 0;
}


/**
 * 方法二：利用map存放差值。
 * 简单起见，这次ans中存储的是值，而非位置。
 * 
*/
bool two_number_sum2(vector<int>& v, int sum, pair<int,int>& ans){
    map<int,int> lack; //用来记录元素与sum的差值。
    bool flag = false;

    for(int i=0; i<v.size(); i++){
        if(lack[v[i]]){//如果当前值=缺少的值(在map)，找到
            ans.first=v[i];
            ans.second=sum-v[i];
            flag = true;
            break;
        }else{
            lack[sum-v[i]]++;
        }
    }

    return flag;
}


/**
 * 方法一：利用归并排序
 * **/
bool two_number_sum1(vector<int>& v, int sum, pair<int,int>& ans){
    Merge_Sort(v,0,v.size()-1);
    int i=0,j=v.size()-1;
    bool flag = false;

    while(i<j){
        if(v[i]+v[j] == sum){
            ans.first = i;
            ans.second = j;
            flag = true;
            break;
        }else if(v[i]+v[j] < sum)
            i++;
        else
            j--;
    }

    return flag;
}

/***************************************/
/**归并排序*/
 
void Merge_Sort(vector<int>& v,int start,int end){
    vector<int> tmp(end-start+1);
    int left=start,right=end;
    merge_sort(v,left,right,tmp);
}
 
void merge_sort(vector<int>& v,int left,int right,vector<int>& tmp){
    if(left<right){
        int mid = (left+right)/2;
        merge_sort(v,left,mid,tmp);
        merge_sort(v,mid+1,right,tmp);
        merge_sort_vector(v,left,mid,right,tmp);
    }
}
 
void merge_sort_vector(vector<int>& v,int left,int mid,int right,vector<int>& tmp){
    //分治法中，合并有序向量
    int i=left,j=mid+1,t=0;
    while(i<=mid && j<=right){
        if(v[i]<v[j])
            tmp[t++]=v[i++];
        else
            tmp[t++]=v[j++];
    }
    while(i<=mid)
        tmp[t++]=v[i++];
    while(j<=right)
        tmp[t++]=v[j++];
    t=0;
    while(left<=right)
        v[left++]=tmp[t++];
}
 
/***************************************/


void printf_vector(const vector<int>& v){
    for(int i=0; i< v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}