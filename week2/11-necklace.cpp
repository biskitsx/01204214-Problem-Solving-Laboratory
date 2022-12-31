#include<iostream>
using namespace std; 

int main() {
    int n, i, next, begin ,connect;
    int neckLace[300001] = {0}; 

    // cout << neckLace[4] ;
        
    cin >>  n ; 
    int sum = n*(n+1)/2 ; 

    for (i=0;i<n-1;i++) {
        cin >> next >> begin ;

        //begin is never use 
        // cout << neckLace[begin] ; 
        if (neckLace[begin] == 0) {
            neckLace[begin] = next ;
            sum -= begin ; 
            // cout << sum << endl ; 
        }

        //begin is already used 
        else {
            connect = neckLace[begin] ;
            neckLace[begin] = next ;
            int lastBegin = begin ;
            while(1) {
                if (neckLace[lastBegin]==0) {
                    break;
                }
                lastBegin = neckLace[lastBegin] ;
            }
            neckLace[lastBegin] = connect ;
            sum -= lastBegin ; 
            // cout << sum << endl ; 
        }
    }

    int start = n - sum ;
    cout << start << ' '; 
    while(1) {
        if (neckLace[neckLace[start]] == 0) {
            cout << neckLace[start] ;
            break;
        }
        cout << neckLace[start] << ' ';
        start = neckLace[start] ; 
    }
}