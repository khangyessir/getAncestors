#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> reverveGraph;
        for(const auto &edge : edges){
            reverveGraph[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> result(n);
        for(int i=0; i<n; ++i){
            unordered_set<int> ancestors;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int nei : reverveGraph[node]){
                    if(ancestors.find(nei) == ancestors.end()){
                        ancestors.insert(nei);
                        q.push(nei);
                    }
                }
            }
            vector<int> ancestorsList(ancestors.begin(), ancestors.end());
            sort(ancestorsList.begin(), ancestorsList.end());
            result[i] = ancestorsList;
        }
        return result;
    }
};
