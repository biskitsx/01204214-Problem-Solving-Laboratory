#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int main() {
    int n,k,i,tpr ;
    int fastest = 100000 ;
    unordered_map <int,int> tprs ; 

    //input and find fastest
    cin >> n >> k ; 
    for( i = 0 ; i < n; i++ ) {
        cin >> tpr ; 
        tprs[i]= tpr ; 
        if (tpr < fastest) {
            fastest = tpr ; 
        }
    }


    //comparison
    int runnerLeft = n ;
    fastest *= k ;
    for (i = 0; i< n;i++) {
        if (tprs[i]*(k-1) >= fastest) {
            runnerLeft--;
        }
    }
    cout << runnerLeft ;

}