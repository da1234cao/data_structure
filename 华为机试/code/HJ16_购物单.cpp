// 题解参考：https://blog.csdn.net/weixin_45965762/article/details/118773265
// 参考题解使用滚动数组来写动态规划，我这里使用二维数组

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

int main(int argc, char const *argv[]){
    ////////////////////读取输入
    int N,m;
    cin>>N>>m;

    
    vector<int> zj(m + 1), zjvw(m + 1), fj1(m + 1), fj2(m + 1), fj1vw(m + 1), fj2vw(m + 1);

    for(int i=1; i<=m; i++){
        int price, weight, is_main;
        cin>>price>>weight>>is_main;

        if(is_main == 0){
            zj[i] = price;
            zjvw[i] = price*weight;
        }else if(fj1[is_main] == 0){
            fj1[is_main] = price;
            fj1vw[is_main] = price*weight;
        }else if(fj2[is_main] == 0){
            fj2[is_main] = price;
            fj2vw[is_main] = price*weight;
        }
    }

    ////////////////////////数据预处理
    // 由于题目规定，价格均为10的倍数，我们可以将价格均缩小十倍
    // 结果再乘10

    ////////////////////动态规划
    vector<vector<int>> dp(m+1, vector<int>(N+1,0));
    for(int i=1; i<=m; i++){ // 先遍历物品
        for(int j=1; j<=N; j++){ // 再扩大背包
            if(zj[i]!=0 && j >= zj[i]){ // 当主件可以放入时
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-zj[i]] + zjvw[i]); // 放 or 不放
                if(fj1[i]!=0 && j >= zj[i]+fj1[i]){ // 当主件和附件1可以放入时
                    dp[i][j] = max(dp[i][j], dp[i-1][j-zj[i]-fj1[i]] + zjvw[i] + fj1vw[i]);
                }
                if(fj2[i]!=0 && j >= zj[i]+fj2[i]){ // 当主件和附件2可以放入时
                    dp[i][j] = max(dp[i][j], dp[i-1][j-zj[i]-fj2[i]] + zjvw[i] + fj2vw[i]);
                }
                if(fj1[i]!=0 && fj2[i]!=0 && j >= zj[i]+fj1[i]+fj2[i]){ // 当主件和附件1,2可以放入时
                    dp[i][j] = max(dp[i][j], dp[i-1][j-zj[i]-fj1[i]-fj2[i]] + zjvw[i] + fj1vw[i] + fj2vw[i]);
                }
            }else{ // 放入不了，则继承
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[m][N];

    return 0;
}
