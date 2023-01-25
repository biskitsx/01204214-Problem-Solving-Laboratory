#include<iostream>  
#include<vector>
#include<queue>

using namespace std;

vector <int> adj[100001] ;
int type[100001] = {0} ; 
int deg[100001] = {0}  ;

int n, m, s, t ;
int i, j ;
int a, b ;

bool visited[100001] ;
int layer[100001] ;


void clear() {
    int i ;
    for (i=0;i<=n+1;i++) {
        visited[i] = false ;
        layer[i] = 0 ; 
    }
}

void bfs(int start) {
    queue <int> q ;

    clear() ; 
    visited[start] = true ;
    layer[start] = 0 ;
    q.push(start) ;

    while(!q.empty()) {
        int curr = q.front() ;
        if (type[curr] == 1) {
            cout << layer[curr] << '\n'; 
            break; 
        }
        q.pop() ; 

        int i ;
        for (i = 0; i < deg[curr]; i++) {
            int next = adj[curr][i] ; 
            if (!visited[next]) {
                visited[next] = true ;
                layer[next] = layer[curr] + 1 ;
                if (type[next] == 1) {
                    cout <<layer[next] << '\n';  
                    return ; 
                }
                q.push(next) ; 
            }
        }
    }
}

void readInput() {
    cin >> n >> m >> s >> t;
    //edge
    int i ;
    for (i=0;i<m;i++) {
        cin >> a >> b;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
        deg[a]++ ;
        deg[b]++ ;
    }
    //determine stock as 1
    for (i=0;i<s;i++) {
        cin >> a ;
        type[a] = 1 ;
    }

    for (i=0;i<t;i++) {
        cin >> a ;
        // type[b] = 0 ;
        // cout << "bug\n" ; 
        bfs(a) ; 
    }
}

int main() {
    readInput() ;
}