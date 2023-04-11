#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


int n, m ;
double map[21][21] ;
vector <double> keep ; 
vector <pair<int,int> > dir ; 
double minny = 0xfffff;
int minVal ;

void init() {
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(0,-1));
}

void readInput() {
    cin >> n >> m ;
    for (int i = 0 ; i < n ; i++) {
        for (int j=0;j<m;j++) {
            cin >> map[i][j] ; 
        }
    }
}

//direction 
//0 : up , 1 : right, 2 : down, 3 : left
void findValue(int x, int y, double val,int z) {
    if (x >= n || x < 0 || y >= m || y < 0) {
        return ;
    }
    
    double deltaVal = abs(val-map[x][y]) ; 
    keep.push_back(deltaVal) ; 

    findValue(x+dir[z].first,y+dir[z].second,val,z); 
}


double avgWrong(int i, int j) {
    keep.clear() ;
    findValue(i+1,j,map[i][j],0) ;
    findValue(i,j+1,map[i][j],1) ;
    findValue(i-1,j,map[i][j],2) ;
    findValue(i,j-1,map[i][j],3) ;

    double avgEach = 0 ;
    // cout << "this is keep : " ;
    for (auto e : keep) {
        // cout << e << ' ' ;
        avgEach += e ;
    }
    // cout <<endl ;
    avgEach /= keep.size() ;
    return avgEach ;
}


int main() {
    readInput() ;
    init() ;
    for (int i=0; i < n; i++) {
        for (int j=0; j<m;j++) {
            if (avgWrong(i,j) < minny) {
                minny = avgWrong(i,j);
                minVal = map[i][j] ;
            }

        }
    }
    cout  << minVal ;
}
