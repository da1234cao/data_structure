#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backTracking(const vector<pair<int,int>> nums, const int m, const int n, int start_index, int& zero_cnt, int& one_cnt, int& len, int& result){
        if(m>=zero_cnt && n>=one_cnt){
            if(len > result)
                result = len;
        }

        for(int i=start_index; i<nums.size(); i++){
            zero_cnt += nums[i].first;
            one_cnt += nums[i].second;
            len++;
            backTracking(nums,m,n,i+1,zero_cnt,one_cnt,len,result);
            len--;
            one_cnt -= nums[i].second;
            zero_cnt -= nums[i].first;
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> nums(strs.size(),pair<int,int>(0,0));
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            for(char zero_or_one : str)
                if(zero_or_one == '0')
                    nums[i].first++;
                else
                    nums[i].second++;
        }

        int zero_cnt=0, one_cnt=0, len=0, result=0;
        backTracking(nums,m,n,0,zero_cnt,one_cnt,len,result);

        return result;
    }
};