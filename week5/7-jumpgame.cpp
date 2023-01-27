#include<iostream>
#include<vector>
using namespace std;

int n, k, i, j, h;
int s = 0 ;
vector<int> adj[21] ;
bool visited[21][21] = {{false}} ; 

void readInput() {
    cin >> n >> k ;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            cin >> h ;
            adj[i].push_back(h) ; 
        }
    }
}

void travel(int x,int y,int prevHeight) {

    // cout << x << ' ' << y << '\n'; 
    
    //is it in map 
    if (x < 0 || y < 0 || x >= n || y >= n) {
        // cout << "1bug\n";
        return ;
    }

    //is it visited
    if (visited[x][y]) {
        // cout << "2bug\n";
        return ; 
    }

    //is it heigher than jumping
    int currentHeight = adj[x][y] ; 
    if (currentHeight > prevHeight + k) {
        // cout << "3bug\n";
        return ; 
    }


    if (x==n-1 && y==n-1) {
        s++ ; 
    }
    visited[x][y] = true ; 
    
    travel(x+1,y,currentHeight) ; 
    travel(x-1,y,currentHeight) ;
    travel(x,y+1,currentHeight) ;
    travel(x,y-1,currentHeight) ;

}

int main() {
    readInput() ; 
    travel(0,0,adj[0][0]) ;

    if (s==0) {
        cout << "no\n" ;
    }
    else {
        cout << "yes\n" ;
    }
    return 0 ;
}