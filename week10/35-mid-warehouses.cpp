#include<iostream>
#include<vector>

using namespace std ;

int n, m, k;
int a, b ;
int root[100001];

void init() {
    for (int i=1 ; i<n ; i++) {
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

void readInput() {
    cin >> n >> m >> k;
    init();
    for (int i=0; i<m; i++) {
        cin >> a >> b ;
        if (parent(a) != parent(b)) {
            unionFind(a,b) ;
        }
    }
}
int main() {
    readInput();
    int u, v;
    for (int i=0; i<k ;i++) {
        cin >> u >> v ;
        if (parent(u) != parent(v)) {
            cout << 0 <<endl ;
        }
        else {
            cout << 1 <<endl;
        }
    }
}
