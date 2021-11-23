#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 返回拓扑排序序列
        vector<int> result;
        unordered_map<int,vector<int>> point_to;
        vector<int> in_degree(numCourses,0); //课程编号是0-numCourses-1。我们用向量下标表示课程，具体值表示入度；省的用map

        for(auto prerequisite : prerequisites){
            point_to[prerequisite[1]].push_back(prerequisite[0]);
            in_degree[prerequisite[0]]++;
        }

        queue<int> Q; // 存放入度为零的节点
        for(int i=0; i<numCourses; i++){
            if(in_degree[i] == 0)
                Q.push(i);
        }

        while(!Q.empty()){
            int course = Q.front();
            Q.pop();
            result.push_back(course);
            for(auto nod : point_to[course]){
                in_degree[nod]--;
                if(in_degree[nod] == 0)
                    Q.push(nod);
            }
        }

        return result.size() == numCourses ? result:vector<int>();
    }
};