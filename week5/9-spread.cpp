#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n, m;
int u, v, w ; 
double t ;
int maxEdge = 0  ;

int speed[100001] ;
int root[200001] ; 

using edge = pair<int,pair<int,int> > ;
set <edge> Graph ;

void readInput() {
    cin >> n >> m  ;

    //get speed 
    for (int i = 1 ; i<n+1; i++) {
        cin >> speed[i] ; 
    }

    //get Edge weight = time 
    for (int i = 0; i < m ;i++) {
        cin >> u >> v >> w ;

        t = w*1.0/((speed[u]+speed[v])*1.0) ; 
        if ((int)t != t) {
            t = int(t) + 1;
        }

        
        // cout << "node : "<< u << ' ' << v << "time : " << t << endl;
        Graph.insert(make_pair(t,make_pair(u,v))) ; 
    }
}

void init() {
    for (int i = 1; i < n+1 ; i++) {
        root[i] = i ;
    }
}

int parent(int x) {
    if (x == root[x]) {
        return x ;
    }
    root[x] = parent(root[x]) ; 
    return root[x];

}

void unionFind(int x,int y) {
    int a = parent(x) ;
    int b = parent(y);
    root[a] = root[b] ; 
}

void kruskal() {
    for (auto e : Graph) {
        int u = e.second.first ;
        int v = e.second.second ;
        int t = e.first ;

        if (parent(u) != parent(v)) {
            unionFind(u,v); 
            maxEdge = max(maxEdge,t) ;
            // cout << "node : " << u << ' ' << v << "  and time : " << t <<endl ;
        }
    }
}

int main() {
    readInput() ;
    init() ; 
    kruskal() ;
    cout << maxEdge ; 
}