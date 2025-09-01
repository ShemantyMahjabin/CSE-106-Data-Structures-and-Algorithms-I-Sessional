#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*class graph {

    vector<vector<int>> adj;
public:
   /* graph(int n) {
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
  }
   int distanceBFS(int source, int destination, stack<int>& ans) {
    vector<int> parent(adj.size(), -1);
    unordered_set<int> visited;
    queue<pair<int, int>> q;
    visited.insert(source);
    q.push({source, 0});

    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();

        if (node == destination) {
            int curr = destination;
            while (curr != source) {
                ans.push(curr);
                curr = parent[curr];
            }
            ans.push(source);

            return distance;
        }

        for (int neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push({neighbor, distance + 1});
                visited.insert(neighbor);
                parent[neighbor] = node;
            }
        }
    }

    return -1;
}

int distanceDFS(int source, int destination, queue<int>& path) {
    static unordered_set<int> visited;
    visited.insert(source);
    path.push(source);

    if (source == destination) {
        return 0;
    }

    for (int neighbour : adj[source]) {
        if (visited.find(neighbour) == visited.end()) {
            int newDistance = distanceDFS(neighbour, destination, path);
            if (newDistance != -1) {
                return newDistance + 1;
            }
        }
    }

    path.pop();
    return -1;
}
};*/
bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<vector<int>> bfs(int x, int y, int k, int n, int m) {
    vector<vector<int>> distances(n, vector<int>(m, -1));
    vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

    queue<pair<int, int>> q;
    q.push({x, y});
    distances[x][y] = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (const auto& dir : directions) {
            int nx = cx + dir.first;
            int ny = cy + dir.second;

            if (isValid(nx, ny, n, m) && distances[nx][ny] == -1 && k > 0) {
                distances[nx][ny] = distances[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    return distances;
}

int solve(int n, int m, int q, const vector<pair<pair<int, int>, int>>& riders) {
    int totalMinMoves = INT_MAX;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int minMoves = 0;
            bool isValidCell = true;

            for (const auto& rider : riders) {
                const int x = rider.first.first;
                const int y = rider.first.second;
                const int k = rider.second;

                vector<vector<int>> distances = bfs(x, y, k, n, m);

                if (distances[i][j] == -1) {
                    isValidCell = false;
                    break;
                }

                minMoves += (distances[i][j] + k - 1) / k;
            }

            if (isValidCell) {
                totalMinMoves = min(totalMinMoves, minMoves);
            }
        }
    }

    return (totalMinMoves != INT_MAX) ? totalMinMoves : -1;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<pair<int, int>, int>> riders(q);
    for (int i = 0; i < q; ++i) {
        cin >> riders[i].first.first >> riders[i].first.second >> riders[i].second;
    }

    int result = solve(n, m, q, riders);
    cout << result << endl;

    return 0;
}
