#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

int n, m;
int speed[100001] ;
int u, v, w;
int i, j;
int second = 0 ;
int countConnect ;
vector<pair<int,int> > graph[100001] ;
vector<int> connectedGraph[100001] ; 
int connectCount ;

void readInput() {
    cin >> n >> m ;

    for (i=1;i<=n;i++) {
        cin >> speed[i] ;
    }

    for (i=0;i<m;i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
}

void bfs() {
    queue<int> q ;

    vector<bool> visited ;
    visited.resize(n+1,false) ;

    q.push(1) ; 
    visited[1] = true ; 
    connectCount = 1 ;
    
    while(!q.empty()) {
        int curr = q.front() ;
        q.pop() ; 

        for (i = 0; i < connectedGraph[curr].size(); i++) {
            int next = connectedGraph[curr][i] ; 
            if (!visited[next]) {
                visited[next] = true ;
                q.push(next) ; 
                connectCount++ ; 
            }
        }
    }
}

void updateDistance(int x,int y) {
    graph[x][y].second -= speed[x] ; 
    int next = graph[x][y].first, i ;  
    for (i=0;i<graph[next].size();i++) {
        if (graph[next][i].first == x) {
            graph[next][i].second -= speed[x] ; 
            // cout <<"after delete : "<< graph[next][i].second <<endl ;
        }
    }

    if (graph[x][y].second <= 0) {
        connectedGraph[x].push_back(graph[x][y].first) ; 
        connectedGraph[graph[x][y].first].push_back(x) ; 
    }

}

void eachSecond() {
    for (i=1;i<=n;i++) {
        for (j=0;j<graph[i].size();j++) {
            if (graph[i][j].second <= 0) {
                continue; 
            }

            updateDistance(i,j) ; 
            // cout << '(' << graph[i][j].first << ',' << graph[i][j].second << ") ";

        }
    }
    second++ ; 
}

void findTime() {
    while(connectCount != n) {
        eachSecond() ;
        bfs() ; 
    }

    cout << second << endl ;
}

int main() {
    readInput() ; 
    findTime() ;
}