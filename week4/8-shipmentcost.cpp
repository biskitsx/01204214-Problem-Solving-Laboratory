#include<iostream>  
#include<vector>

using namespace std;

vector <int> adj[10001] ;
int type[10001] = {0} ; 

int n, m, s, t ;
int i, j ;
int a, b ;

void readInput() {
    cin >> n >> m >> s >> t;
    //edge
    for (i=0;i<m;i++) {
        cin >> a >> b;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }
    //determine stock as 0 
    for (i=0;i<s;i++) {
        cin >> a ;
        type[a] = 0 ;
    }
    //determine factory as 1 
    for (i=0;i<s;i++) {
        cin >> a ;
        type[b] = 1 ;
    }
}


int main() {
    readInput() ;
}