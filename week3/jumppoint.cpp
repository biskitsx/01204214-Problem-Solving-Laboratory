#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std ;

int n,r,i,j ;
int u,v  ;

vector <int> adjList[100001] ;
pair <int,int> coor[100001] ;
int layer[100001] = {-1} ;


void createPair(int index,int u,int v) {
    pair <int,int> p ;
    p.first = u ;
    p.second = v ;
    coor[index] = p ;
}

void checkR(int oldCoor) {
    float oldX = coor[oldCoor].first*1.0 ;
    float oldY = coor[oldCoor].second*1.0 ;
    float distance = sqrt((oldX-u*1.0)*(oldX-u*1.0)+(oldY-v*1.0)*(oldY-v*1.0)) ;

    if (distance <= r) {
        adjList[oldCoor].push_back(i) ; 
        adjList[i].push_back(oldCoor) ; 
    }
}
void readInput() {
    cin >> n >> r ;

    //init
    createPair(0,0,0) ;
    createPair(n+1,100,100) ;

    for (i=1;i<=n;i++) {
        cin >> u >> v ;
        
        createPair(i,u,v) ;

        for (j=0;j<i;j++) {
            checkR(j) ; 
        }
        checkR(n+1) ; 
    }

}

void bfs() {
    queue <int> q ;
    int start = 0 ;
    bool visited[100000] ={false}; 
    layer[start]=  0;
    
    visited[start] = true ;
    q.push(start) ; 

    while(!q.empty()) {
        int curr = q.front() ;
        // cout << curr << endl ;
        q.pop() ; 

        size_t i ;
        for (i=0;i < adjList[curr].size();i++) {
            int next = adjList[curr][i] ;
            if (!visited[next]) {
                visited[next] = true ;
                layer[next] = layer[curr]+1 ;
                q.push(next) ; 
            }
        }
    }
}
int main() {
    readInput() ; 
    bfs();
    cout << (layer[n+1] > 0 ? layer[n+1] : -1); 

}