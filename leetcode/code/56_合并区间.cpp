#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct cmp{
        bool operator() (vector<int>& v1, vector<int>& v2){
            return v1[0]<v2[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return {{}};
        if(intervals.size()==1)
            return intervals;
        
        sort(intervals.begin(),intervals.end(),cmp());

        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= end){ // 与之前合并的区间有重合
                end = max(end,intervals[i][1]);
                continue;
            }
            result.push_back({start,end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
        result.push_back({start,end}); // 统计最后一个合并区间
        
        return result;
    }
};