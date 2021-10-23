#include <vector>
#include <unordered_set>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 核心思想：将石头尽量分成对等的两份；然后，互相消耗

        int sum = 0;
        for(int stone : stones)
            sum += stone;
        int bag_weight = sum/2;
        vector<vector<int>> dp(stones.size(),vector<int>(bag_weight+1,0)); 
        // 第一列初始化：当背包空间为0，可以放入的值为0
        // 第一行初始化：因为当无法放入时，需要继承上一行的值，所以需要初始化第一行
        for(int i=stones[0]; i<=bag_weight; i++)
            dp[0][i] = stones[0];
        
        // 尽量把背包装满 == 尽量将石头分为相等的两半
        for(int i=1; i<stones.size(); i++){ // 遍历物品
            for(int j=1; j<=bag_weight; j++){ // 遍历背包
                if(stones[i]>j) // 无法放入
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]]+stones[i]); // 可以放入，使用max判断是否放入   
            }
        }

        // for(auto v : dp){
        //     for(auto i : v)
        //         cout<<i<<" ";
        //     cout<<endl;
        // }

        // 统计放入背包中的是哪些时候 == 挑出一半重量的石头
        // 方法：再一件件取出物品
        unordered_set<int> half;
        int i=stones.size()-1;
        int j=bag_weight;
        while(i>=0 && j>=0 && dp[i][j]!=0){
            if(i>=1 && (dp[i][j] == dp[i-1][j])) // i物品并不在背包里面
                i = i-1;
            else{ // 取出物品
                half.insert(i);
                j = j-stones[i];
                i = i-1;
            }
        }

        // 另一半石头的下标
        unordered_set<int> other_half;
        for(i=0; i<stones.size(); i++)
            if(!half.count(i))
                other_half.insert(i);
        

        // 将两堆石头分别放入两个栈中
        stack<int> s1;
        stack<int> s2;
        unordered_set<int>::iterator it;
        for(it=half.begin(); it!=half.end(); it++)
            s1.push(stones[*it]);
        for(it=other_half.begin(); it!=other_half.end(); it++)
            s2.push(stones[*it]);
        
        // 两堆石头互相消耗
        while(!s1.empty() && !s2.empty()){
            int stone1 = s1.top();
            s1.pop();
            int stone2 = s2.top();
            s2.pop();
            if(stone1 == stone2)
                continue;
            else if(stone1 > stone2)
                s1.push(stone1 - stone2);
            else
                s2.push(stone2 - stone1);
        }

        // 统计剩余石头
        int result = 0;
        if(s1.empty() && s2.empty())
            ;
        else if(!s1.empty() && s2.empty()){
            while(!s1.empty()){
                result += s1.top();
                s1.pop();
            }
        }else{
           while(!s2.empty()){
               result += s2.top();
               s2.pop();
           }
        }
        
        return result;
    }
};

int main(void){
    vector<int> stones = {2,7,4,1,8,1};
    Solution s;
    cout<<s.lastStoneWeightII(stones);
}