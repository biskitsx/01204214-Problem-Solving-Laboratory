#include<iostream>
#include<vector>
using namespace std ;

vector<char> maze[21] ; 
bool visited[21][21] ;
int n, q ;
char u ;
int i, j ;
int r, c, a, b ;
bool go = false;


void resetAll() {
    int i ;
    go = false ;
    for (i=0;i<21;i++) {
        for (j=0;j<21;j++) {
            visited[i][j] = false ; 
        }
    }
}

void readInput() {
    cin >> n >> q ;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            cin >> u ;
            maze[i].push_back(u); 
        }
    }
}

void traversal(int row,int column,bool key) {

    //we arrive it
    if (row == a-1 && column == b-1) {
        go = true ;
        return ;
    }

    //is it in map
    if (row < 0 || row >= n || column < 0 || column >= n) {
        // cout << map[row][column] << endl ; 
        return ;
    }

    //is it visited
    if (visited[row][column]) {
        return ; 
    }

    //is it a wall
    if (maze[row][column] == '#') {
        return ;
    }

    //is it a door
    if (maze[row][column] == 'O') {
        if (!key) {
            key = true ; 
        }
        else 
            return ;
    }

    visited[row][column] = true ; 

    traversal(row-1,column,key) ;
    traversal(row+1,column,key) ;
    traversal(row,column-1,key) ;
    traversal(row,column+1,key) ;
}


void yesNo() {

    for (i=0;i<q;i++) {
        resetAll() ;
        cin >> r >> c >> a >> b ;
        traversal(r-1,c-1,false) ; 

        if (go) {
            cout << "yes\n" ;
        }
        else {
            cout << "no\n" ;
        }
    }
}
int main() {
    readInput() ; 
    yesNo() ; 
}
