#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n){
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }

    int findRoot(int x){
        while(x != parent[x])
            x = parent[x];
        return x;
    }

    bool isConnect(int x, int y){
        return findRoot(x) == findRoot(y);
    }

    void unionSet(int x, int y){
        int root_x = findRoot(x);
        int root_y = findRoot(y);
        if(root_x == root_y){
            ;
        }else{
            parent[root_x] = root_y;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // 将相连序列，放入同一个集合中
        int N = s.size();
        UnionFind uf(N);
        for(auto pir : pairs){
            uf.unionSet(pir[0], pir[1]);
        }

        // 将相同集合中的元素，进行排序。使用map<int,priority_queue<char>>。int为集合的根坐标，优先队列对以该int为根的集合进行升序排序
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>> set_sorted;
        for(int i=0; i<N; i++){
            int root_i = uf.findRoot(i);
            set_sorted[root_i].push(s[i]);
        }

        // 根据下标，从下标对应的集合中，pop出最小的元素
        string result(N,'\0');
        for(int i=0; i<N; i++){
            int root_i = uf.findRoot(i);
            char ch = set_sorted[root_i].top();
            set_sorted[root_i].pop();
            result[i] = ch;
        }

        return result;
    }
};