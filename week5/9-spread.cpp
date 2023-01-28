#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

int n, m;
int diffusion[100001] ;
int u, v, w;
int i, j;
vector<pair<int,int> > graph[100001] ;

void readInput() {
    cin >> n >> m ;

    for (i=1;i<=n;i++) {
        cin >> diffusion[i] ;
    }

    for (i=0;i<m;i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
}


int main() {
    
}