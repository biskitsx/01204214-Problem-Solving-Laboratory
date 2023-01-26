#include<iostream>
#include<vector>
using namespace std;

char map[31][31] ;
bool visited[31][31] ;
bool go = false ;
int n, m ;
int i, j;

void readInput() {
    cin >> n >> m ;
    for (i=0 ; i < n ; ++i) {
        for (j=0; j < m;j++) {
            cin >> map[i][j] ;
            if (map[i][j] == '#') {
                visited[i][j] = true ;
            }
        }
    } 
}

void travel(int x,int y) {

    if (x == n-2 && map[x+1][y] == '.' && map[x][y+1] == '.' && map[x+1][y+1] =='.' ) {
        go = true ; 
        return ;
    }

    if (x < 0 || x >= m || y < 0 || y >= n) {
        return ;
    }

    if (visited[x][y]) {
        return ;
    }

    visited[x][y] = true; 

    if (map[x+1][y] == '.' && map[x][y+1] == '.' && map[x+1][y+1] == '.') {
        travel(x+1,y) ;
        travel(x-1,y) ; 
        travel(x,y+1) ; 
        travel(x,y-1) ; 
    }

}

void start() {
    for (i=0;i<m-1;i++) {
        if (map[0][i] == '.') {
            travel(0,i) ; 
        }
    }
}

int main() {
    readInput();
    start() ;

    if (go) {
        cout << "yes\n";
    }
    else {
        cout << "no\n" ; 
    }
}