#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

int n,m,i,j,x;
vector <int> adj[31] ;
bool visited[31][31] ;

void readInput() {
    cin >> n >> m ;
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            cin >> x ;
            adj[i].push_back(x) ;
        }
    }
}


int main() {

}