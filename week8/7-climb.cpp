#include<iostream>

using namespace std;

int n, m;
char map[31][31] ; 
int minPower = 100000 ;
bool visited[31][31] = {false} ;

void readInput() {
    cin >> n >> m ;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j] ; 
        }
    }
}

void travel(int x, int y, int power) {
    if (x < 1 || x > n || y < 1 || y > m) {
        return ;
    }
    
    if (map[x][y] == 'X') {
        return ; 
    }

    if (power > minPower) {
        return ; 
    }

    if (visited[x][y]) {
        return ;
    }

    if (y == m && x == 1) {
        minPower = min(minPower, power) ; 
        // cout << "we found it with power " << x << ' ' << y << " with " << minPower <<endl ;
        return ;
    }

    visited[x][y] = true ;

    travel(x-1, y, power+5) ; //up
    travel(x+1, y, power) ;   //down
    travel(x, y+1, power+1) ; //right
    travel(x, y-1, power+1) ; //left

    visited[x][y] = false;
}

int main() {
    readInput() ;

    travel(n, 1, 0) ;
    cout << minPower ; 
}