#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int main() {
    int n,k,i,tpr,fastest ;
    unordered_map <int,int> tprs ; 

    //input 
    cin >> n >> k ; 
    for( i = 0 ; i < n; i++ ) {
        cin >> tpr ; 
        tprs[i] = tpr ; 
    }

    //find fastest 
    fastest = tprs[0] ; 
    for (i=0;i<n;i++) {
        if (tprs[i]< fastest) {
            fastest = tprs[i] ; 
            tprs[i] = 0 ;
        } 
    }

    int runnerLeft = n ;
    fastest *= k ;
    for (i = 0; i< n;i++) {
        if (tprs[i]*(k-1) >= fastest) {
            runnerLeft--;
        }
    }
    cout << runnerLeft ;
}