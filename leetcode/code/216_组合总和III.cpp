#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int k, int n, int startIndex, int endIndex){
        // 递归出口
        if(path.size() == k){
            if(accumulate(path.begin(),path.end(),0) == n)
                result.push_back(path);
            return;
        }

        for(int i=startIndex; path.size()+(endIndex-i+1)>=k; i++){
            path.push_back(i);
            backTracking(k,n,i+1,endIndex);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(k,n,1,9);
        return result;
    }
};