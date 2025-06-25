class Solution {

    bool hasCycle(vector<vector<int>>&graph,vector<int>&visited,int node){
        if(visited[node]==1) return true;
        if(visited[node]==2) return false;

        visited[node]=1;//visiting
        for(int neighbor:graph[node]){
            if(hasCycle(graph,visited,neighbor)) return true;
        }
        visited[node]=2; //visited
        return false;

    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto&pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }
        vector<int>visited(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(hasCycle(graph,visited,i)) return false;
        }
        return true;
    }
};
 #include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}