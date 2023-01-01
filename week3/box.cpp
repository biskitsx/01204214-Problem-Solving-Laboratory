#include<iostream>
#include<vector>
using namespace std;

vector <int> adj[31] ;
vector <bool> hinder[31] = {{false}} ; 

int n, m ; 
int i, j ;
char s ; 


//input 
void readInput() {
    cin >> n >> m ;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            cin >> s ;
            adj[i].push_back(s) ; 
            if (s == '#') {
                hinder[i][j] = true ;
            }
        }
    }
}

int x1,x2,y1,y2  ; 
//coor
//x1,y1
//x1,y2
//x2,y1
//x2,y2


void moveBox() {
    if ()
}


int main() {
    readInput() ; 

}