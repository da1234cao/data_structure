#include <vector>
#include <iostream>

using namespace std;

class quickSort {
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
    quickSort(){
        srand((unsigned)time(NULL));
    }

    void sort(vector<int>& nums) {
        RandomQuickSort(nums,0,nums.size()-1);
    }
};


class Solution {
private:
    void bucketSort(vector<int>& nums){
        if(nums.empty())
            return;

        // 桶排序
        int BUCKETSIZE = 100; // 桶大小为100

        int min_val = nums[0];
        int max_val = nums[0];
        for(auto num : nums){
            if(num < min_val)
                min_val = num;
            else if(num > max_val)
                max_val = num;
        }

        int counts = max_val-min_val+1;
        int bucker_num = (counts%BUCKETSIZE == 0) ? counts/BUCKETSIZE : counts/BUCKETSIZE+1; // 需要的桶的数量
        vector<vector<int>> buckets(bucker_num,vector<int>());

        // 把元素放入不同区间的桶中
        int n = nums.size();
        for(int i=0; i<n; i++){
            int bucker_i = (nums[i]-min_val)/BUCKETSIZE;
            buckets[bucker_i].push_back(nums[i]);
        }

        // 每个桶进行排序
        quickSort qsort;
        int i=0;
        for(auto& bucket : buckets){
            qsort.sort(bucket);
            for(auto num : bucket)
                nums[i++] = num;
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        bucketSort(nums);
        return nums;
    }
};    

int main(void){
    vector<int> nums = {-74,48,-20,2,10,-84,-5,-9,11,-24,-91,2,-71,64,63,80,28,-30,-58,-11,-44,-87,-22,54,-74,-10,-55,-28,-46,29,10,50,-72,34,26,25,8,51,13,30,35,-8,50,65,-6,16,-2,21,-78,35,-13,14,23,-3,26,-90,86,25,-56,91,-13,92,-25,37,57,-20,-69,98,95,45,47,29,86,-28,73,-44,-46,65,-84,-96,-24,-12,72,-68,93,57,92,52,-45,-2,85,-63,56,55,12,-85,77,-39};
    Solution sol;
    vector<int> ans = sol.sortArray(nums);
    for(int num : ans)
        cout<<num<<" ";
}