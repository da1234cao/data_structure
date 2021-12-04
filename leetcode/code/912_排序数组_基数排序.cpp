#include <vector>
#include <iostream>

using namespace std;

class Solution {
    private:
    /**
     * 按照数组v的exp位进行计数排序
     * exp=1,按照个位排序
     * exp=10,按照十位排序
     * exp=100,按照百位排序
    */
    void radixCoutingSort(vector<int> &v,int exp){
        int v_size = v.size();
        vector<int> output(v_size,0);
        vector<int> counts(10,0);

        for(int i=0; i<v_size; i++)
            counts[v[i]/exp%10]++;
        for(int i=1; i<counts.size(); i++)
            counts[i]+=counts[i-1];
        // for(int i=0; i<v_size; i++){
        // 稳定排序，必须从后向前，因为相同数字的填充是向前填充的
        for(int i=v_size-1; i>=0; i--){
            output[counts[v[i]/exp%10]-1]=v[i];
            counts[v[i]/exp%10]--;
        }
        for(int i=0; i<v_size; i++)
            v[i]=output[i];
        return;
    }

    // 基数排序
    void radixSort(vector<int> &v){
        int max=v[0];
        for(int i=1; i<v.size(); i++)
            if(v[i]>max)
                max=v[i];
        for(int exp=1; max/exp>0; exp*=10)
            radixCoutingSort(v,exp);
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        radixSort(nums);
        return nums;
    }
};    

int main(void){
    // 所有自然数排序
    vector<int> nums = {2,1,23,6,18,2};
    Solution sol;
    vector<int> ans = sol.sortArray(nums);
    for(int num : ans)
        cout<<num<<" ";
}