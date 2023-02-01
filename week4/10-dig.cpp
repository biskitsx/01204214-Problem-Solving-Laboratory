#include<iostream>
#include<vector>
using namespace std;

int r, c ;
int a, b, x, y ;
int i, j ;

int maze[51][51] ; 
int visited[51][51] = {false};
bool arived = false ;
int min = 0xfffffff ;

void readInput() {
    cin >> r >> c >> a >> b >> x >> y ;
    for (i=1;i<=r;i++) {
        for (j=1;j<=c;j++) {
            cin >> maze[i][j] ; 
            if (maze[i][j] == '#') {
                visited[i][j] = true ;
            }
        }
    }
}

void travel(int row,int column,bool isDig) {
    if (row < 0 || row >= r || column < 0 || column >= c || visited[row][column]) {
        return ;
    }

    travel(row+1,column,isDig,);
    travel(row-1,column,isDig);
    travel(row,column+1,isDig);
    travel(row,column-1,isDig);
}

int main() {
    readInput();
    return 0 ;
}