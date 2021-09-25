#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        // 递归出口
        if(path.size() == k){
            result.push_back(path);
            return;
        }

        for(int i=startIndex; path.size()+n-i+1 >=k; i++){ // 剪枝操作
            path.push_back(i); // 选择元素
            backtracking(n,k,i+1);
            path.pop_back(); // 回溯时，弹出之前选择的元素
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return result;
    }
};