#include<iostream>
#include<vector>

using namespace std ;

int n, m, x;
vector <int> root ;
int u, v;

void init() {
    for (int i=0 ; i<=n; i++) {
        root[i] = i ;
    }
}

void readInput() {
    cin >> n >> m;
    root.resize(n+1);
    for (int i=2 ; i<=n ;i++) {
        cin >> x ;
        root[i] = x;
    }
}

int findFamily() {
    int du = u ;
    int dv = v ;

    if (u==1||v == 1) {
        return 1 ;
    }

    vector <int> rootCopy = root ;

    while (rootCopy[du] != du ) {
        if (du == v) {
            return v ;
        }
        // rootCopy[du] = rootCopy[rootCopy[du]] ; 
        du = rootCopy[du]  ;
    }

    rootCopy = root ;
    while (rootCopy[dv] != dv ) {
        if (dv == u) {
            return u ;
        }
        // rootCopy[dv] = rootCopy[rootCopy[dv]] ; 
        dv = rootCopy[dv]  ;
    }
    return -1 ;
    
}

int main() {
    readInput();

    for (int i=0 ; i<m; i++) {
        cin >> u >> v ;
        cout << findFamily() <<endl;
    }
}