#include<iostream>  
#include<vector>
#include<queue>

using namespace std;

vector <int> adj[100001] ;
vector <int> factory ; 
queue <int> q ;

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

    while(!q.empty()) {
        int curr = q.front() ;
        q.pop() ; 
        int i ;
        for (i = 0; i < adj[curr].size(); i++) {
            int next = adj[curr][i] ; 
            if (!visited[next]) {
                visited[next] = true ;
                layer[next] = layer[curr] + 1 ;
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
    }

    clear() ; 
    for (i=0;i<s;i++) {
        cin >> a ;
        q.push(a) ;
        layer[a] = 0 ;  
        visited[a] = true ;

    }

    for (i=0;i<t;i++) {
        cin >> a ;
        factory.push_back(a) ; 
    }
}

int main() {
    readInput() ;
    bfs(q.front()) ;

    for (i=0;i<t;i++) {
        cout << layer[factory[i]] << '\n' ; 
    }

}