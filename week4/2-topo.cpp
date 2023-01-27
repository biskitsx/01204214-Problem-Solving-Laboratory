#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#define MAX_N 1000000

using namespace std;

int n, m ;
int u, v ;
int i, j ;

unordered_map<int, vector<int>> adj; 
unordered_map<int, int> inDegree; 
priority_queue<int, vector<int>, greater<int>> pq;
vector<bool> visited;

void readInput() {
    cin >> n >> m ;
    visited.resize(n+1,false);
    for (i = 0 ; i < m ;i ++) {
        cin >> u >> v ;
        adj[u].push_back(v) ; 
        inDegree[v]++;
    }
}

void topoSort() {
    for (i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        cout << u << endl;
        visited[u] = true;

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0 && !visited[v]) {
                pq.push(v);
            }
        }
    }
}

int main() {
    readInput();
    topoSort();
    return 0;
}
