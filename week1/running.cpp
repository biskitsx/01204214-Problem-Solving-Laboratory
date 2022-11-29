#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int main() {
    int n,k,i,tpr,fastest ;
    unordered_map <int,int> tprs ; 
    unordered_map <int,int> map ;


    //input 
    cin >> n >> k ; 
    for( i = 0 ; i < n; i++ ) {
        cin >> tpr ; 
        tprs[i] = tpr ; 
    }
    map = tprs ;
    //find fastest 
    fastest = tprs[0] ; 
    for (i=0;i<n;i++) {
        if (tprs[i]< fastest) {
            fastest = tprs[i] ; 
            tprs[i] = 0 ;
        }
    }

    int runnerLeft = n ;
    int currentTime = fastest ;
    int round = 2 ;
    while (1) {
        if (round == k+1) {
            break ; 
        }
        currentTime += fastest ;
        for (i=0;i<n;i++) {
            if (tprs[i]==0) {
                continue;
            }
            if (currentTime <= tprs[i]) {
                runnerLeft-- ; 
                tprs[i] = 0; 
                continue;
            }
            tprs[i] += map[i] ; 
        }
        round++ ; 
    }

    cout << runnerLeft ;


    

}