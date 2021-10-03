#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void backTraing(vector<vector<string>>& tickets, map<string,vector<pair<string,bool>>>& tickets_map, string start ,vector<string>& path, vector<vector<string>>& all_path){
        // 每张票只能用一次，当所有票串联使用一次时候，为一条航线
        // 节点 = 边 + 1
        if(path.size() == tickets.size()+1){
            // for(auto str : path)
            //     cout<<str<<" ";
            cout<<endl;
            all_path.push_back(path);
            return;
        }

        vector<pair<string,bool>>& ends = tickets_map[start];
        int size = ends.size();
        for(int i=0; i<size; i++){
            if(ends[i].second) // 已经使用过的票，不可再用
                continue;
            ends[i].second = true;
            path.push_back(ends[i].first); // 新的票加入路径
            backTraing(tickets,tickets_map,ends[i].first,path,all_path); // 使用当前票的目标点，作为新的起点
            path.pop_back();
            ends[i].second = false;
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 数据预处理，将数据处理为map<start,vector<pair<end,uesd>>> -- 起点，重点，是否使用
        map<string,vector<pair<string,bool>>> tickets_map;
        for(auto tickets : tickets){
            string start = tickets[0];
            string end = tickets[1];
            tickets_map[start].push_back(make_pair(end,false));
        }

        // 回溯遍历，将所有票可一次串联成功的路径，放入all_path中
        string start("JFK");
        vector<string> path; 
        vector<vector<string>> all_path;
        path.push_back(start);
        backTraing(tickets,tickets_map,start,path,all_path);

        // cout<<"<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        // for(auto path : all_path){
        //     for(auto str : path)
        //         cout<<str<<" ";
        //     cout<<endl;
        // }
        // cout<<">>>>>>>>>>>>>>>>>>>>>>"<<endl;

        // 返回字典序排序最小的组合
        // 注意：以字典序比较两个字符串在C++20中被移除
        vector<string>& min_result = all_path[0]; // 题目已经限制，至少存在一条路径
        int size = all_path.size();
        for(int i=1; i<size; i++){
            vector<string>& now_path = all_path[i];
            for(int j=0; j<tickets.size(); j++){
                if(now_path[j] < min_result[j]){
                    min_result = now_path;
                    break;
                }else if(now_path[j] > min_result[j])
                    break;
            }
        }

        // 返回结果
        vector<string> result = min_result;
        return result;
    }
};

int main(void){
    // vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    // vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<vector<string>> tickets = {{"AXA","EZE"},{"EZE","AUA"},{"ADL","JFK"},{"ADL","TIA"},{"AUA","AXA"},{"EZE","TIA"},{"EZE","TIA"},{"AXA","EZE"},{"EZE","ADL"},{"ANU","EZE"},{"TIA","EZE"},{"JFK","ADL"},{"AUA","JFK"},{"JFK","EZE"},{"EZE","ANU"},{"ADL","AUA"},{"ANU","AXA"},{"AXA","ADL"},{"AUA","JFK"},{"EZE","ADL"},{"ANU","TIA"},{"AUA","JFK"},{"TIA","JFK"},{"EZE","AUA"},{"AXA","EZE"},{"AUA","ANU"},{"ADL","AXA"},{"EZE","ADL"},{"AUA","ANU"},{"AXA","EZE"},{"TIA","AUA"},{"AXA","EZE"},{"AUA","SYD"},{"ADL","JFK"},{"EZE","AUA"},{"ADL","ANU"},{"AUA","TIA"},{"ADL","EZE"},{"TIA","JFK"},{"AXA","ANU"},{"JFK","AXA"},{"JFK","ADL"},{"ADL","EZE"},{"AXA","TIA"},{"JFK","AUA"},{"ADL","EZE"},{"JFK","ADL"},{"ADL","AXA"},{"TIA","AUA"},{"AXA","JFK"},{"ADL","AUA"},{"TIA","JFK"},{"JFK","ADL"},{"JFK","ADL"},{"ANU","AXA"},{"TIA","AXA"},{"EZE","JFK"},{"EZE","AXA"},{"ADL","TIA"},{"JFK","AUA"},{"TIA","EZE"},{"EZE","ADL"},{"JFK","ANU"},{"TIA","AUA"},{"EZE","ADL"},{"ADL","JFK"},{"ANU","AXA"},{"AUA","AXA"},{"ANU","EZE"},{"ADL","AXA"},{"ANU","AXA"},{"TIA","ADL"},{"JFK","ADL"},{"JFK","TIA"},{"AUA","ADL"},{"AUA","TIA"},{"TIA","JFK"},{"EZE","JFK"},{"AUA","ADL"},{"ADL","AUA"},{"EZE","ANU"},{"ADL","ANU"},{"AUA","AXA"},{"AXA","TIA"},{"AXA","TIA"},{"ADL","AXA"},{"EZE","AXA"},{"AXA","JFK"},{"JFK","AUA"},{"ANU","ADL"},{"AXA","TIA"},{"ANU","AUA"},{"JFK","EZE"},{"AXA","ADL"},{"TIA","EZE"},{"JFK","AXA"},{"AXA","ADL"},{"EZE","AUA"},{"AXA","ANU"},{"ADL","EZE"},{"AUA","EZE"}};
    Solution s;
    vector<string> result = s.findItinerary(tickets);
    for(auto str : result)
        cout<<str<<" ";
}