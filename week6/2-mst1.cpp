#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair <int, pair<int ,int> > edge[1001] ; 
int root[1001] ;

int n, m, i, minWeight = 0;

void readInput() {
    int u, v, w, i ;
    cin >> n >> m ;
    for (i=0;i<m;i++) {
        cin >> u >> v >> w ;
        edge[i] = make_pair(w,make_pair(u,v)) ;
    }
    sort(edge,edge+m);
}

void init() {
    for (i=1;i<=n;i++) {
        root[i] = i ;
    }
}

int parent(int x) {
    while (root[x] != x ) {
        root[x] = root[root[x]] ; 
        x = root[x]  ;
    }
    return x ;
}

void unionFind(int x,int y) {
    int a = parent(x) ; 
    int b = parent(y) ; 
    root[a] = root[b] ; 
}

void kruskal() {
    for (i=0;i<m;i++) {
        int u = edge[i].second.first ;
        int v = edge[i].second.second ;
        int w = edge[i].first ; 

        //ถ้าไม่เกิด cycle node จะเชื่อมกัน
        if (parent(u) != parent(v)) {
            minWeight += w ; 
            unionFind(u,v) ; 
        }
    }
}

int main() {
    readInput() ; 
    init() ;
    kruskal() ; 
    cout << minWeight << endl; 
}