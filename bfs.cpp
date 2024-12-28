#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

void floodPrediction(const vector<vector<int>>& graph, vector<int> sources) {
    int V = graph.size();
    vector<int> floodedTime(V, -1);  // -1 indicates not flooded yet
    queue<int> q;

    for (int source : sources) {
        floodedTime[source] = 0;
        q.push(source);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor = 0; neighbor < V; ++neighbor) {
            if (graph[node][neighbor] && floodedTime[neighbor] == -1) { // If connected and not flooded
                floodedTime[neighbor] = floodedTime[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Output the flood times
    for (int i = 0; i < V; ++i) {
        cout << "Region " << i << ": ";
        if (floodedTime[i] == -1) cout << "Not Flooded";
        else cout << "Flooded at time " << floodedTime[i];
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };

    vector<int> sources = {0};  // Starting flood from region 0

    floodPrediction(graph, sources);
    return 0;
}
