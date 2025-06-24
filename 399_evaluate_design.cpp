#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<string, unordered_map<string, double>> graph;
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

    using namespace std;

    class Solution
    {
    public:
        unordered_map<string, unordered_map<string, double>> graph;

        double dfs(string curr, string target, unordered_set<string> &visited)
        {
            if (graph.find(curr) == graph.end())
                return -1.0;
            if (curr == target)
                return 1.0;

            visited.insert(curr);
            for (auto &neighbor : graph[curr])
            {
                if (visited.count(neighbor.first))
                    continue;
                double result = dfs(neighbor.first, target, visited);
                if (result != -1.0)
                {
                    return result * neighbor.second;
                }
            }
            return -1.0;
        }

        vector<double> calcEquation(
            vector<vector<string>> &equations,
            vector<double> &values,
            vector<vector<string>> &queries)
        {

            for (int i = 0; i < equations.size(); ++i)
            {
                string a = equations[i][0], b = equations[i][1];
                double val = values[i];
                graph[a][b] = val;
                graph[b][a] = 1.0 / val;
            }

            // Step 2: Answer each query
            vector<double> results;
            for (auto &q : queries)
            {
                string a = q[0], b = q[1];
                unordered_set<string> visited;
                double res = dfs(a, b, visited);
                results.push_back(res);
            }

            return results;
        }
    };
};
int main()
{
    return 0;
}
