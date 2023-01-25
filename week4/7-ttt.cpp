#include<iostream>
#include<vector> 
#include<queue>

using namespace std;

int n, m, i, j, u, v;

void isBipartite(vector<int> adjList[]){    
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
                cout << u << ' ' << next  << '\n';
                return ;
            }
        }
    }
    return ;

}


int main() {    


    cin >> n >> m ;
    vector <int> adjList[n+1] ; 
    for (i=0;i<m;i++) {
        
        //graph
        
        //color

        cin >> u >> v ;
        adjList[u].push_back(v) ;
        adjList[v].push_back(u) ;  
        //set all color -> -1 


    }
    
    isBipartite(adjList) ;
}