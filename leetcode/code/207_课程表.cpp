#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 拓扑排序[[a<-b],[c<-d]]

        unordered_map<int,list<int>> courses_into_degree; // 记录节点的所有入度（其实记录入度数即可，不需要记录具体的入度）
        unordered_map<int,list<int>> courses_out_degree; // 记录节点的所有出度
        set<int> nodes; // 统计所有节点
        queue<int> Q;
        
        // 将prerequisites，统计进入courses_into_degree
        // 顺道记录下图中存在的节点
        for(auto prerequisite : prerequisites){
            nodes.insert(prerequisite[0]);
            nodes.insert(prerequisite[1]);
            courses_into_degree[prerequisite[0]].push_back(prerequisite[1]); // 记录入度
            courses_out_degree[prerequisite[1]].push_back(prerequisite[0]); // 记录出度
        }

        // 将所以入度为零的课程，放入队列
        for(auto n : nodes){
            if(courses_into_degree.find(n) == courses_into_degree.end())
                Q.push(n);
        }

        int cnt = 0;
        while(!Q.empty()){
            cnt++;
            int n = Q.front();
            Q.pop();
            for(auto& course : courses_out_degree[n]){ // 根据出度，直接找到目标节点；删除该目标节点，相应的入度
                auto it = find(courses_into_degree[course].begin(),courses_into_degree[course].end(),n);
                courses_into_degree[course].erase(it);
                if(courses_into_degree[course].empty()){ // 擦除入度之后，入度为零
                    Q.push(course);
                    auto it=courses_into_degree.begin(); //(入度被删除之后，对应的数据结构节点不需要删除)
                    for(it; it!=courses_into_degree.end(); it++)
                        if(it->first == course)
                            break;
                    courses_into_degree.erase(it);
                }
            }
        }

        return nodes.size() == cnt ? true : false;

    }
};