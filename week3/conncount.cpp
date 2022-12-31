#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

const int MAX_N = 100010 ; 


vector<int> adjList[MAX_N] ; 
bool visited[MAX_N] ={false} ; 

int n,m,i ; 

void readInput() {
    cin >> n >> m ;
    for (i=0;i<m;i++) {
        int u,v ;
        cin >> u >> v ;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(int start) {
    queue <int> q ;

    visited[start] = true ;
    q.push(start) ;

    while(!q.empty()) {
        int curr = q.front() ;
        q.pop() ; 


        for (i = 0; i < adjList[curr].size(); i++) {
            int next = adjList[curr][i] ; 
            if (!visited[next]) {
                visited[next] = true ;
                q.push(next) ; 
            }
        }
    }
}

int concount() {
    int i ;
    int count = 0 ;
    for (i=1;i<=n;i++) {
        if (!visited[i]) {
            count++ ; 
            bfs(i) ; 
        }
    }
    return count ;
}

int main() {
    readInput() ; 
    cout << concount() ; 
}