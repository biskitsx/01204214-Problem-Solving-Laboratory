#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, i;
int a, b, c, s ;

vector <pair <int,int> > adjList[1001] ;
bool expressWay[1001][1001] ={{false}}; 
bool visited[1001] = {false} ; 


void readInput() {
    cin >> n >> m ;
    for (i=0;i<m;i++) {
        cin >> a >> b >> c >> s;
        
        //insert graph 
        adjList[a].push_back(make_pair(b,c)) ;
        adjList[b].push_back(make_pair(a,c)) ;

        //determine express way 
        if (s==1) {
            expressWay[a][b] = true ;
            expressWay[b][a] = true ;
        }
    }
}

void bfs() {
    queue <int> q ;
    int start = 1 ;
    visited[start] = true ;
    q.push(start) ;

    while(!q.empty()) {
        int curr = q.front() ;
        q.pop() ; 
        cout << curr << endl ;

        for (i = 0; i < adjList[curr].size(); i++) {
            int next = adjList[curr][i].first ; 
            if (!visited[next]) {
                visited[next] = true ;
                q.push(next) ; 
            }
        }
    }
}

int main() {
    readInput() ;
    bfs() ;
}