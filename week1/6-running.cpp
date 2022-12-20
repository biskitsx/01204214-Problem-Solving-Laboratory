#include<iostream>
using namespace std ;
int tpm[100010] ;


int main() {
    int i , runnerLeft ; 
    double fastest = 10000000,n,k ;
    int time ; 

    //get n and k 
    cin >> n >> k ;
    runnerLeft = n ;
    for (i = 0 ; i < n ; i++) {
        cin >> time ; 
        tpm[i] = time ; 
        if (time < fastest) {
            fastest = time ;
        }
    }

    for (i = 0 ; i < n ; ++i) {
        if (((fastest*k*1.00)/tpm[i]+0.0) <= k-1) {
            runnerLeft-- ; 
        }
    }
    cout << runnerLeft ;
    return 0 ;
}