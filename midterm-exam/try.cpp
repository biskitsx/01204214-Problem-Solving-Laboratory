#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int r, c, a, b, x, y; 
int i, j;

int countries[101][101] ; 
bool visited[101] = {false}; 
int visaCount = 0 ;
int layer[101] = {0} ; 
vector<int> graph[101] ; 

void readInput() {
    cin >> r >> c >> a >> b >> x >> y ;
    for (i=1;i<=r;i++) {
        for (j=1;j<=c;j++) {
            cin >> countries[i][j] ;
        }
    }
}

bool isAdd(int u, int v) {
    int i =0;
    for (i=0;i<graph[u].size();i++) {
        if (graph[u][i] == v) {
            return true ;
        }
    }
    return false ;
}

void checkNear() {
    // cout << "what\n" ; 
    for (i=1;i<r;i++) {
        for (j=1;j<c;j++) {
            int curr = countries[i][j] ;
            int right = countries[i][j+1] ;
            int down = countries[i+1][j] ; 

            if (curr != right) {
                if (!isAdd(curr,right)) {
                    graph[curr].push_back(right) ;
                    graph[right].push_back(curr) ;
                    // cout << "ADD : " << curr << " and " << right <<endl ;
                }
            }
            if (curr != down) {
                if(!isAdd(curr,down)) {
                    graph[curr].push_back(down);
                    graph[down].push_back(curr); 
                }
            }
        }
    }
}

void bfs(int start,int end) {
    queue <int> q ;

    visited[start] = true ;
    q.push(start) ;
    layer[start] = 0 ;

    while(!q.empty()) {
        int curr = q.front() ;
        q.pop() ; 


        for (i=0;i < graph[curr].size();i++) {
            int next = graph[curr][i] ;
            if (!visited[next]) {
                visited[next] = true ;
                layer[next] = layer[curr]+1 ;
                q.push(next) ; 
            }
        }
    }
    // return layer[next] ; 
}

int main() {
    readInput();
    checkNear() ;
    // cout <<countries[a][b] << endl ;
    // cout <<countries[x][y] << endl ;
    bfs(countries[a][b],countries[x][y]);
    cout << layer[countries[x][y]] ;

}