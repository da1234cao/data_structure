#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 目标：满足数量尽可能多的孩子(限制：每个孩子一块饼干)
        // 贪心策略：从胃口较小的孩子进行分配，分配的时候选择满足胃口的最小饼干。(或者从大胃口，大饼干分配也可)
        // 贪心策略证明：小胃口分配大饼干，不合理；大胃口分配小饼干，白白消耗算力

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int sum = 0;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(g[i]<=s[j]){ // 当前饼干，为大于孩子胃口饼干中，最小的那个
                    sum += 1;
                    s[j] = 0; // 将该饼干重量清零
                    break;
                }
            }
        }

        return sum;
    }
};