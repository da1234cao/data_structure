#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 核心思路：贪心。每次取最大的两个石头互相粉碎。
        // 经测试，存在错误。反例：[31,26,33,21,40]---》5？？？

        // 将石头从大大小插入multiset
        multiset<int,greater<int>> stones_set;
        for(int i=0; i<stones.size(); i++)
            stones_set.insert(stones[i]);
        

        while(stones_set.size()!=0 && stones_set.size()!=1){
            auto it = stones_set.begin();
            int stone1 = *(it);
            stones_set.erase(it);
            cout<<"stone choice: "<<stone1<<"       ";
            it = stones_set.begin();
            int stone2 = *(it);
            stones_set.erase(it);
            cout<<"stone choice: "<<stone2<<"       ";

            if(stone1-stone2 != 0){
                stones_set.insert(stone1 - stone2);
                cout<<"stone push: "<<stone1-stone2<<"       ";
            }
            cout<<endl;
        }   

        if(stones_set.size() == 0)
            return 0;
        return *stones_set.begin();    
    }
};

int main(void){
    vector<int> stones = {31,26,33,21,40};
    Solution s;
    cout<<s.lastStoneWeightII(stones);
}