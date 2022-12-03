#include<iostream>
using namespace std ;

int main() {
    int i ;
    long runnerLeft,time ; 
    long timesPerRound[1000000];
    long fastest = 100000 ,k,n;

    //input and find fastest runner 
    cin >> n >> k ;
    for (i=0;i<n;i++) {
        cin >> time ; 
        timesPerRound[i] = time; 
        if (time < fastest) {
          fastest = time ; 
        }
    }

    runnerLeft = 5 ;
    
    //find runner left 
    for (i=0;i<n;i++) {
        if ((fastest*k*1.00)/(timesPerRound[i]+0.0) <= k-1) {
            runnerLeft-- ; 
        }
    }
    cout << runnerLeft ; 
}