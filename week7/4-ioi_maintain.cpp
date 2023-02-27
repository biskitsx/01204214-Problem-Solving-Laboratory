#include<iostream>
#include<vector>
#include<queue>
#include<set> 

using namespace std ;

int root[10001] ;

int n, m, i;
int u, v, w; 

using edge = pair <int,pair<int,int> > ; 

set <edge> Graph ; 

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
    int i ,cost = 0 ;
    for (auto e : Graph) {
        int u = e.second.first ;
        int v = e.second.second ;
        int w = e.first ;

        if(parent(u) != parent(v)) {
            cost += w ; 
            unionFind(u,v) ; 
        }
    }

    // ถ้าไปไม่ครบทุกสวนให้ cost = -1 
    int theParent = parent(1) ; 
    for (i=1;i<n+1;i++) {
        if (theParent != parent(i)) {
            cost = -1 ;
            break;
        }
    }
    cout << cost << endl ; 
    return ; 
}

void clearRootWent() {
    int i ;
    for (i=1;i<=n;i++) {
        root[i] = i ; 
    }
}

int main() {
    cin >> n >> m ;
    for (i=0;i<m;i++) {
        clearRootWent() ; 
        cin >> u >> v >> w ;
        Graph.insert(make_pair(w,make_pair(u,v)));
        kruskal() ; 
    }
}