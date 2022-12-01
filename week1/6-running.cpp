#include<iostream>
#include<vector>
using namespace std ;

int main() {
    double n,k,i ; 
    double time ;
    double fastest = 100000 ;
    vector <double> timesPerRound ;

    //input and find fastest runner 
    cin >> n >> k ;
    for (i=0;i<n;i++) {
        cin >> time ; 
        timesPerRound.push_back(time) ; 
        fastest = time < fastest ? time : fastest ; 
    }


    double runnerLeft = n  ;
    //max Time for running
    double maxTime = fastest * k ;
    
    //find runner left 
    for (i=0;i<n;i++) {
        double roundRunner = maxTime/timesPerRound[i] ; 
        if (roundRunner <= k-1) {
            runnerLeft-- ; 
        }
    }
    cout << runnerLeft ; 
}