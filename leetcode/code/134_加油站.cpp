#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        multimap<int,int> gas_i; // <汽油量，下标>
        for(int i=0; i<gas.size(); i++){
            gas_i.insert(make_pair(gas[i],i));
        }

        multimap<int,int>::iterator it;
        for(it=gas_i.begin(); it!=gas_i.end(); it++){ // 从大于始发站需要汽油量，从大到小选择
            int gas_count = 0;
            int cost_count = 0;
            int loc = it->second;
            int i;
            for(i=0; i<gas.size(); i++){
                gas_count += gas[loc];
                cost_count += cost[loc];
                if(gas_count < cost_count)
                    break;
                loc = (loc+1)%gas.size();
            }
            if(i==gas.size()) break;
        }

        return it==gas_i.end() ? -1 : it->second;
    }
};

int main(void){
    vector<int> gas  = {2,0,1,2,3,4,0};
    vector<int> cost = {0,1,0,0,0,0,11};
    Solution s;
    cout<<s.canCompleteCircuit(gas,cost);
}