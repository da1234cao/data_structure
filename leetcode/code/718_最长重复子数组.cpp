#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // 暴力解
        // 最长连续重复序列 == nums1[i:] nums2[j:]的最长连续前缀
        int result = 0;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int tmp = 0;
                int ii = i;
                int jj = j;
                while(ii<nums1.size() && jj<nums2.size() && nums1[ii] == nums2[jj]){
                    tmp++;
                    ii++;
                    jj++;
                }
                result = max(result,tmp);
            }
        }

        return result;
    }
};

int main(void){
    vector<int> nums1 = {0,0,0,0,0,0,1,0,0,0};
    vector<int> nums2 = {0,0,0,0,0,0,0,1,0,0};
    Solution s;
    cout<<s.findLength(nums1,nums2)<<endl;
}