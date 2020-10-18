/**
 * 描述：最大子数组问题
 * 参考：https://leetcode-cn.com/problems/maximum-subarray/solution/dong-tai-gui-hua-fen-zhi-fa-python-dai-ma-java-dai/
 * 方法一：暴力，时间复杂度O(n^2)
 * 方法二：贪心，未证明
 * 方法三：分治法
*/

#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

void maxSubVector1(vector<int>& v, pair<int,int>& loc, int& retmax);
void maxSubVector2(vector<int>& v, int& retmax);
void maxSubVector3(vector<int>& v, int& retmax);
int maxSubVector3Sum(const vector<int>& v,int left,int right);
int maxCrossingSum(const vector<int>& v,int left,int mid,int right);


int main(void){
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    int start=3, end=6, max=6; // 这是答案
    pair<int,int> loc; int retmax=INT32_MIN; // 通过函数记录答案在变量中

    // // 暴力法测试
    // maxSubVector1(v,loc,retmax);
    // if(loc.first==start && loc.second==end && max==retmax)
    //     cout<<"True"<<endl;
    // else
    //     cout<<"false"<<endl;

    // // 贪心法测试
    // maxSubVector2(v,retmax);
    // if(max==retmax)
    //     cout<<"True"<<endl;
    // else
    //     cout<<"false"<<endl;

    // 分治法测试
    maxSubVector3(v,retmax);
    if(max==retmax)
        cout<<"True"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}


/********************************************************************/
/********************************************************************/
void maxSubVector3(vector<int>& v, int& retmax){
    // 方法三：分治法。
    // 最大子序和在左边/中间/右边
    if(v.size()==0)
        return;
    retmax = maxSubVector3Sum(v,0,v.size()-1);
}

int maxSubVector3Sum(const vector<int>& v,int left,int right){
    if(left==right)
        return v[left];
    int mid = (left+right)/2;
    return max(max(maxSubVector3Sum(v,left,mid),maxSubVector3Sum(v,mid+1,right)),maxCrossingSum(v,left,mid,right));
}

int maxCrossingSum(const vector<int>& v,int left,int mid,int right){
    int max_left_sum=INT32_MIN,max_right_sum=INT32_MIN;
    int tmp_sum=0;
    for(int i=mid; i>=left;i--){
        tmp_sum += v[i];
        if(tmp_sum > max_left_sum)
            max_left_sum = tmp_sum;
    }
    tmp_sum=0;
    for(int i=mid+1;i<=right;i++){
        tmp_sum += v[i];
        if(tmp_sum > max_right_sum)
            max_right_sum = tmp_sum;
    }
    return max_left_sum+max_right_sum;
}

/********************************************************************/
/********************************************************************/
void maxSubVector2(vector<int>& v, int& retmax){
    // 方法二：贪心。如果之前的元素和不能做贡献则丢弃
    // 最优子结构的特征?

    // 向量长度是0或者1 直接返回
    if(v.size()==0)
        return;

    retmax=v[0];
    int cursum=v[0];
    for(int i=0;i<v.size()-1;i++){
        cursum = max(v[i],cursum+v[i]);//v[i]之前不能做贡献的元素和丢弃，保证只有贡献，才能保留
        retmax = max(cursum,retmax); // retmax始终存储查找到的最大值
    }
}

/********************************************************************/
/********************************************************************/
void maxSubVector1(vector<int>& v, pair<int,int>& loc, int& retmax){
    // 方法一：暴力法，遍历首尾位置

    // 向量长度是0或者1 直接返回
    if(v.size()==0)
        return;
    if(v.size()==1){
        loc.first=loc.second=0;
        retmax=v[0];
        return;
    }

    // 稍微优化点，我们用一个数组存储前缀和，便于计算子数组和
    // 这一步可以省略，在下面边计算求和，边前进
    vector<int> prefixSum(v.size());
    prefixSum[0]=v[0];
    for(int i=1; i<v.size();i++){
        prefixSum[i]=prefixSum[i-1]+v[i];
    }

    retmax=INT32_MIN;
    int tmp;
    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            tmp = prefixSum[j]-prefixSum[i]+v[i];
            if(tmp > retmax){
                loc.first = i;
                loc.second = j;
                retmax = tmp;
            }
        }
    }

}