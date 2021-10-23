#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void zeroOneCnt(const string& str, pair<int,int>& zero_one_cnt){
        for(char ch : str)
            if(ch == '0')
                zero_one_cnt.first++;
            else
                zero_one_cnt.second++;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // 动态规划：dp[i][j][k],表示从前i个物品中选择，其中0的个数不超过j，1的个数不超过k，的最多的物品个数
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,0)));

        // 初始化三维数组的一个面；其余两个面m=0 or n=0,时，一个也无法装入，为0
        pair<int,int> zero_one_cnt;
        zeroOneCnt(strs[0], zero_one_cnt);
        for(int i=zero_one_cnt.first; i<=m; i++){
            for(int j=zero_one_cnt.second; j<=n; j++)
                dp[0][i][j] = 1;
        }

        for(int i=1; i<strs.size(); i++){
            pair<int,int> zero_one_cnt;
            zeroOneCnt(strs[i], zero_one_cnt);
            for(int j=0; j<=m; j++){
                for(int k=0; k<=n; k++){
                    if(j>=zero_one_cnt.first && k>=zero_one_cnt.second)
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zero_one_cnt.first][k-zero_one_cnt.second]+1); // 能放下，看放下值不值
                    else
                        dp[i][j][k] = dp[i-1][j][k]; // 无法放下，继承
                }
            }
        }

        return dp[strs.size()-1][m][n];
    }
};

int main(void){
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m =5, n = 3;
    Solution s;
    cout<<s.findMaxForm(strs,m,n);
}