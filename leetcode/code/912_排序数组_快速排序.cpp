#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void RandomQuickSort(vector<int>& v, int start,int end){
        if(start<end){
            int p = RandomPartion(v,start,end);
            RandomQuickSort(v,start,p-1);
            RandomQuickSort(v,p+1,end);
        }
    }

    int RandomPartion(vector<int>& v, int start, int end){
        int random_loc = start+rand()%(end-start+1);
        swap(v[start],v[random_loc]);
        return Partion(v,start,end);
    }

    int Partion(vector<int>& v, int low,int high){
        // 这种写法，是严蔚敏《数据结构》中的写法，很容易理解
        int pivot = v[low];
        while(low<high){
            while(low<high && v[high]>=pivot)
                high--;
            v[low]=v[high];
            while(low<high && v[low]<=pivot)
                low++;
            v[high]=v[low];
        }
        v[low]=pivot;
        return low;
    }

public:
    Solution(){
        srand((unsigned)time(NULL));
    }

    vector<int> sortArray(vector<int>& nums) {
        RandomQuickSort(nums,0,nums.size()-1);
        return nums;
    }
};


int main(void){
    vector<int> nums = {5,1,1,2,0,0};
    Solution sol;
    vector<int> ans = sol.sortArray(nums);
    for(int num : ans)
        cout<<num<<" ";
}