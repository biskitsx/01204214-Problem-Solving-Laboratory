#include<iostream>

using namespace std;

int n,m,i,j ;

char map[101][101] ; 
bool visited[101][101] ={{false}}; 

//input
void readInput() {
    cin >> n >> m ;
    for (i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin >> map[i][j] ;
            if (map[i][j] == '#') {
                visited[i][j] = true ; 
            }
        }
    }
}

int normalSpace = 0;
int highSpace = 0 ; 

int countEach = 0; 
int countGrade = 0; 
int keep[2] = {0};
//move
void traversal(int row,int column) {
    if (row < 0 || row >= n || column < 0 || column >= m || visited[row][column] ) {
        // cout << map[row][column] << endl ; 
        return ;
    }

    visited[row][column] = true ; 
    countEach++ ;
 
    if (map[row][column] == '$'){
        keep[0] = 1;
    }

    else if (map[row][column] == '*' ) {
        keep[1] = 1 ;
    }
        
    traversal(row-1,column) ;
    traversal(row+1,column) ;
    traversal(row,column-1) ;
    traversal(row,column+1) ;
}

//
void eachSpace() {
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            if (!visited[i][j]) {

                traversal(i,j) ; 
                countGrade = keep[0] + keep[1] ; 
                if (countGrade == 2) {
                    highSpace += countEach ;
                }
                else if (countGrade == 1) {
                    normalSpace += countEach ; 
                }

                keep[0] = 0 ;
                keep[1] = 0 ;
                countEach = 0 ;
            }
        }
    }

}

int main() {
    readInput() ;
    eachSpace() ; 
    cout << highSpace << ' ' << normalSpace ;
}