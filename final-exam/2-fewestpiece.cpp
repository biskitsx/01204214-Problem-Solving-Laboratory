#include<iostream>
using namespace std;

int m , n; 
int map[31][31] ;
int s[31][31] ;

void readInput() {
    cin >> m >> n ;
    for (int i = 0 ; i < m ;i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> map[i][j] ;
            if (i==0 || j==0) {
                s[i][j] = map[i][j] ;
            }
        }
    }
}

//direction 
// 1 up
// 2 right
// 3 down
// 4 left
int cup(int x,int y,int direction) {
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return 0;
    }

    if (direction == 1) {
        return map[x][y] + cup(x-1,y,1) ;
    }
    else if (direction == 2) {
        return map[x][y] + cup(x,y+1,2) ;
    }
    else if (direction == 3) {
        return map[x][y] + cup(x+1,y,3) ;
    }
    else if (direction == 4) {
        return map[x][y] + cup(x,y-1,4) ;
    }
}

int main() {
    readInput() ;

    for (int i = 0 ; i < m ;i++) {
        for (int j = 0 ; j < n ; j++) {
            if (s[i][j] != 0) {
                continue; 
            }
            int up = cup(i,j,1) ;
            int right = cup(i,j,2) ;
            int down = cup(i,j,3) ;
            int left = cup(i,j,4) ;

            s[i][j] = min(up,min(right,min(down,left))) ;

        }
    }

    for (int i = 0 ; i < m ;i++) {
        for (int j = 0 ; j < n ; j++) {
            cout << s[i][j] << ' ';
        }
        cout << endl ;
    }
}