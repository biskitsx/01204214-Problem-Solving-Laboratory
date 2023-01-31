#include<iostream>
#include<vector> 
#include<queue>

using namespace std;

int k, n, m, i, j, u, v;
int shouldDel ; 

vector<int> adjList[100001] ; 

bool isBipartite(){    
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
                shouldDel == u ; 
                return false ; 
            }
        }
    }
    return true ;

}

void rmVertex() {
    int i, j ;
    for (i=0;i<adjList[shouldDel].size();i++) {
        int v = adjList[shouldDel][i] ; 
        for (auto it = adjList[v].begin();it!=adjList[v].end();++it) {
            if (*it == shouldDel) {
                adjList[v].erase(it) ; 
            }
        }
    }
    adjList[shouldDel].clear() ; 
}

void readInput() {
    cin >> n >> m >> k ;

    for (j=0;j<m;j++) {
            cin >> u >> v ;
            adjList[u].push_back(v) ;
            adjList[v].push_back(u) ;  
            //set all color -> -1 
    }

    while(k!=0) {
        if (isBipartite()) {
            cout << "yes\n" ; 
            break;
        }
        else {
            rmVertex() ; 
            k--;
        }
    }
    cout << "no\n" ;

}

int main() {    
    readInput();
}