#include<iostream>
#include<vector>
#include<queue> 

using namespace std;

const int MAX_N = 100010 ; 


vector<int> adjList[MAX_N] ; 
bool visited[MAX_N] ={false} ; 
int layer[MAX_N] = {0} ; 

int n, m, i, h ; 
int c ; 

void readInput() {
    cin >> n >> m >> h;
    for (i=0;i<m;i++) {
        int u, v ;
        cin >> u >> v ;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void clear() {
    int i ;
    for (i=1 ; i <= n ;i++) {
        visited[i] = false ;
        layer[i] = 0  ;
    }
}

void bfs(int start) {
    queue <int> q ;
    c = 1 ;
    visited[start] = true ;
    layer[start] = 0 ; 
    q.push(start) ;


    while(!q.empty()) {
        int curr = q.front() ;
        if (layer[curr] > h) {
            break; 
        }
        q.pop() ; 


        for (i = 0; i < adjList[curr].size(); i++) {
            int next = adjList[curr][i] ; 
            if (!visited[next]) {
                visited[next] = true ;
                layer[next] = layer[curr] + 1 ;
                if (layer[next] <= h) {
                    c++ ; 
                }
                q.push(next) ; 
            }
        }


    }
}

int eachBfs() {
    int i ,max = 0 ;

    for (i = 1 ; i <= n ; i++) {
        clear() ; 
        bfs(i) ; 
        max = c > max ? c : max ; 
    }
    return max ; 
}

int main() {
    readInput();
    cout << eachBfs() ; 
}