#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> order;

        // Build the graph (adjacency list)
        for (auto &pre : prerequisites)
        {
            int course = pre[0], prereq = pre[1];
            graph[prereq].push_back(course); // prereq → course
        }

        // DFS for each course
        for (int i = 0; i < numCourses; ++i)
        {
            if (visited[i] == 0)
            {
                if (hasCycle(graph, visited, order, i))
                {
                    return {}; // Cycle found → invalid course order
                }
            }
        }

        reverse(order.begin(), order.end()); // reverse postorder gives correct course order
        return order;
    }

private:
    bool hasCycle(vector<vector<int>> &graph, vector<int> &visited, vector<int> &order, int node)
    {
        visited[node] = 1; // mark as visiting

        for (int neighbor : graph[node])
        {
            if (visited[neighbor] == 1)
                return true; // cycle detected
            if (visited[neighbor] == 0)
            {
                if (hasCycle(graph, visited, order, neighbor))
                    return true;
            }
        }

        visited[node] = 2;     // mark as fully visited
        order.push_back(node); // add to ordering after all neighbors are done
        return false;          // no cycle from this node
    }
};

int main()
{
    return 0;
}