#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

int n, m;
int speed[100001] ;
int u, v, w;
int i, j;

double maxTime = 0xfffffff;
int round = 0 ;
int nub = 1 ;

vector<pair<int,double> > graph[100001] ;

double dist[100001] ;
bool visited[100001] ;

//input

void reset() {
    for (i = 1; i <= n; i++) {
        dist[i] = 0xfffffff;
        visited[i] = false ;
    }
}


double findTime() {
    double t = (speed[v]+speed[u])/w ; 
    return t ;
}

void readInput() {
    cin >> n >> m ;

    for (i=1;i<=n;i++) {
        cin >> speed[i] ;
    }

    for (i=0;i<m;i++) {
        cin >> u >> v >> w;
        double time = findTime() ; 

        graph[u].push_back(make_pair(v,time));
        graph[v].push_back(make_pair(u,time));
    }
}

void bfs() {
    reset() ; 
    queue<int> q ; 
    q.push(1) ; 
    visited[1] = true ;

    round++  ;
    nub = 1 ;

    while(!q.empty()) {
        int curr = q.front() ; 
        q.pop() ; 

        int i ;
        for (i=0;i<graph[curr].size();i++) {
            int next = graph[curr][i].first ;
            double time = graph[curr][i].second ; 
            
            if (time > round*1.0) {
                continue;
            }

            if (!visited[next]) {
                nub++ ; 
                visited[next] = true ;
                q.push(next) ; 
            }
        
        }

    }
}

void eachRound() {
    while (1){
        bfs() ; 
        if (nub < n) {
            continue;
        }
        break; 
    }
    cout << round ;
    
}
int main() {
    readInput() ; 
    eachRound()  ;
}