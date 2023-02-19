#include<iostream>
#include<vector>
using namespace std ;

int n, q, i, j, u, v ; 
int root[100001] ; 
char command ; 

int parent(int x) {
    while (root[x] != x) {
        root[x] = root[root[x]] ;
        x = root[x] ; 
    }
    return x; 
}

void unionFind(int a, int b) {
    int c = parent(a) ;
    int d = parent(b) ;
    root[c] = root[d] ; 
}

void init() {
    for (i=1;i<=n;i++) {
        root[i] = i ;
    }
}

int main() {
    cin >> n >> q ;
    init() ; 
    for (i=0;i<q;i++) {
        cin >> command >> u >> v ;

        if (command == 'c') {
            unionFind(u,v) ;
        }

        else {
            if (parent(u) == parent(v)) {
                cout << "yes\n" ; 
            }
            else {
                cout << "no\n" ; 
            }
        }
    }
}