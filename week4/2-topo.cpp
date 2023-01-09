#include<iostream>
#include<vector>
#include<queue>
#define  MAX_N 1000000

using namespace std;

int n, m ;
int u, v ;
int i, j ;
int start ;

vector <int> adj[MAX_N];  
int degree[MAX_N] = {0} ; 
int inDegree[MAX_N] = {0} ; 

void readInput() {
    cin >> n >> m ;
    for (i = 0 ; i < m ;i ++) {
        cin >> u >> v ;
        adj[u].push_back(v) ; 
        inDegree[v]++ ;
        degree[u]++ ;
    }
}

bool isCycle() {
    for (i = 1 ; i <= n ; ++i) {
        if (adj[i].empty()) {
            return false ;
        }
    }
    return true ; 
}

void topoSort() {
    
    // find first inDegree 
    int start ;
    for (i=1;i<=n;i++) {
        if (inDegree[i] == 0) {
            start = i ; 
            break;
        }
    }

    queue <int> q ;
    q.push(start) ;

    for (i=1;i<=n;i++) {
        int u = q.front() ; 
        cout << u << endl ;
        q.pop() ;
        
        //-1 mean this vertex has been deleted
        inDegree[u] = -1 ;
        
        //update in degree 
        for (j=0;j<degree[u];j++) {
            int v = adj[u][j] ; 
            inDegree[v]-- ;
        }

        //find min inDegree
        int min = 100000;
        int cur ;
        for (j=1;j<=n;j++) {
            if (inDegree[j] < min && inDegree[j] != -1) {
                min = inDegree[j] ;
                cur = j ;
                if (min == 0) {
                    break; 
                }
            }
        }
        q.push(cur) ; 

    }

}
void topological() {
    if (isCycle()) {
        cout << "no\n" ;
    }
    else {
        topoSort() ;
    }
}

int main() {
    readInput() ; 
    // cout << inDegree[1] ;
    topological() ; 
}