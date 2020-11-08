#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// //方法一：暴力解法，应对无顺序数组
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         nums1.insert(nums1.end(),nums2.begin(),nums2.end());

//         return middleNum(nums1);
//     }

// private:
//     double middleNum(vector<int>& nums){
//         if(nums.empty())
//             return 0;

//         sort(nums.begin(),nums.end());

//         int len = nums.size();
//         double middle_num = 0;

//         if(len & 1){/*如果长度是奇数，取中间*/
//             middle_num = nums[(len+1)/2-1];
//         }else{
//             middle_num = (nums[len/2-1] + nums[len/2+1-1])/2.0;
//         }

//         return middle_num;
//     }
// };

//方法二：应对两个已经有序的数组；时间复杂度： O(log(m + n))
// 参考有序链表的合并,时间复杂度：m+n
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result = mergeSortedArray(nums1,nums2);
        return middleNum(result);
    }
private:
    vector<int> mergeSortedArray(vector<int>& nums1, vector<int>& nums2){
        int i,j;
        vector<int> MergeResult={};
        for(i=0,j=0; i< nums1.size() && j < nums2.size();){
            if(nums1[i] < nums2[j]){
                MergeResult.push_back(nums1[i]);
                i++;
            }else{
                MergeResult.push_back(nums2[j]);
                j++;
            }
        }
        i==nums1.size() ? MergeResult.insert(MergeResult.end(),nums2.begin()+j,nums2.end()):MergeResult.insert(MergeResult.end(),nums1.begin()+i,nums1.end());
        return MergeResult;
    }

    double middleNum(vector<int>& nums){
        if(nums.empty())
            return 0;

        // sort(nums.begin(),nums.end());
        cout<<endl;

        int len = nums.size();
        double middle_num = 0;

        if(len & 1){/*如果长度是奇数，取中间*/
            middle_num = nums[(len+1)/2-1];
        }else{
            middle_num = (nums[len/2-1] + nums[len/2+1-1])/2.0;
        }

        return middle_num;
    }
};

//方法三：用二分法查找。略。

int main(void){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};

    Solution s;
    cout<<s.findMedianSortedArrays(nums1,nums2)<<endl;

    return 0;
}