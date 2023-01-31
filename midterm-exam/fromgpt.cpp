#include<iostream>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int r, c, a, b, x, y;
int i, j;

int countries[31][31] ;
bool visited[31][31];
int minVisa = 0xfffffff;

void readInput() {
    cin >> r >> c >> a >> b >> x >> y ;
    for (i=1;i<=r;i++) {
        for (j=1;j<=c;j++) {
            cin >> countries[i][j] ;
        }
    }
}

void travel(int row, int column, int visaCount,int lastCountries) {
    if (row == x && column == y) {
        minVisa = min(minVisa,visaCount) ;
        return ;
    }
    if (row > r|| row < 1 || column > c || column < 1) {
        return ;
    }
    if (visited[row][column] == true ) {
        return ;
    }
    int currCountries = countries[row][column] ;
    if (lastCountries != currCountries) {
        visaCount++ ;
    }
    visited[row][column] = true ;

    for (int i = 0; i < 4; i++) {
        int nx = row + dx[i];
        int ny = column + dy[i];

        travel(nx, ny, visaCount, currCountries);
    }

    visited[row][column] = false;
    return ;
}

int main() {
    readInput();
    travel(a,b,0,countries[a][b]) ;
    cout << minVisa << endl;
}

