#include<iostream>
#include<vector>
using namespace std ;

int main() {
    int n,k,i,time;
    float fastest = 100000 ;
    vector <float> timesPerRound ;

    //input and find fastest
    cin >> n >> k ;
    for (i=0;i<n;i++) {
        cin >> time ; 
        timesPerRound.push_back(time) ; 
        fastest = time < fastest ? time : fastest ; 
    }

    //find runner left 
    int runnerLeft = n  ;
    //max Time for running
    float maxTime = fastest * k ;
    for (i=0;i<n;i++) {
        float roundRunner = maxTime/timesPerRound[i] ; 
        if (roundRunner <= k-1) {
            runnerLeft-- ; 
        }
    }
    cout << runnerLeft ; 
}