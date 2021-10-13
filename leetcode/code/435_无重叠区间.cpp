#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct cmp{
        bool operator() (vector<int>& v1, vector<int>& v2){
            // 第一个元素越小越靠前；第一个元素相等，第二个元素越大越靠前，保证屁股越长，越容易被删除
            if(v1[0]<v2[0])
                return true;
            else if(v1[0]==v2[0])
                return v1[1]>v2[1];
            else
                return false;
        }
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0 || intervals.size()==1)
            return 0;

        sort(intervals.begin(),intervals.end(),cmp());

        int count = 0; // 需要被删除的区间
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < end){ // 存在相交，必然要删除一个,选择删除屁股比较长的那个
                count++;
                end = min(end,intervals[i][1]); // 保留屁股较短的那个==删除屁股较长的那个
                continue;
            }
            end = intervals[i][1]; // 使用最新的一个屁股作为end
        }

        return count;
    }
};