#include<iostream>
#include<vector> 
#include<queue>

using namespace std;

int k, n, m, i, j, u, v;

bool isBipartite(vector<int> adjList[]){    
    int color[n+1], i;
    //set all to no colour (-1)
    for (i = 1 ; i <= n ; i++) {
        color[i] = -1 ;
    }

    queue <int> q ;
    q.push(1) ; 
    color[1] = 1 ;

    while (!q.empty()) {
        int u = q.front() ;
        int curColor = color[u] ; 
        q.pop() ;

        for (i = 0 ; i < adjList[u].size() ; ++i) {
            int next = adjList[u][i] ; 

            if (color[next] == -1){
                q.push(next) ; 
                color[next] = 1 - curColor ;
            }

            else if (color[next] == curColor) {
                return false ; 
            }
        }
    }
    return true ;

}


int main() {    
    int count = 0 ;
    cin >> n >> m;
    vector<int> adjList[n+1] ; 
    
    for (i=0;i<m;i++) {
        cin >> u >> v;
        adjList[u].push_back(v) ;
        adjList[v].push_back(u) ;
        if (isBipartite(adjList)) {
            count++ ;
        }
        else {
            cout << count << endl;
            break ;
        }
    }
}