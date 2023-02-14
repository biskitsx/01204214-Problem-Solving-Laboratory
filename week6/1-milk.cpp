#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, q, i, j;
char command ; 
int u, v ;

vector<int> graph[100001] ; 
bool visited[100001] ; 

void reset() {
    int i ; 
    for (i=0;i<n;i++) {
        visited[i] = false ;
    }
}

void bfs(int start,int end) {
    int i;
    reset() ; 
    queue <int> q ;
    visited[start] = true ;
    q.push(start) ;

    while(!q.empty()) {
        int curr = q.front() ;
        q.pop() ; 

        for (i=0;i < graph[curr].size();i++) {
            int next = graph[curr][i] ;
            if (next == end) {
                cout << "yes\n" ;
                return ;
            }
            if (!visited[next]) {
                visited[next] = true ;
                q.push(next) ; 
            }
        }
    }
    cout << "no\n" ; 
    return ;
}


void readInput() {
    cin >> n >> q ;
    for (i=0;i<q;i++) {
        cin >> command >> u >> v ;
        if (command == 'q') {
            bfs(u,v) ; 
        }
        else {
            graph[u].push_back(v) ; 
            graph[v].push_back(u) ;
        }
    }
}

int main () {
    readInput()  ;
}

