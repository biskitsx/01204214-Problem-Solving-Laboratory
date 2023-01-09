#include<iostream>

using namespace std;

int n , i , x , y, tmp; 


int main() {
    cin >> n ;

    int neckLace[900000] = {0}; 

    int sum = n*(n+1)/2 ; 
    for (i=1;i<n;i++) {
        cin >> x >> y ; 
        tmp  = 0; 

        if (neckLace[y] != 0) {
            tmp = neckLace[y] ; 
        }


        neckLace[y] = x ;

        if (tmp != 0 ) {
            while (neckLace[x]!=0) {
                x = neckLace[x] ; 
            }
            neckLace[x]  = tmp ; 
        } 
    }
    int count =  0 ;
    for (i = 1 ; i < n + 1 ; i++) {
        count += neckLace[i] ; 
    }
    int start = sum - count;

    cout << start << ' ' ; 
    while (neckLace[start] != 0 ) {
        cout << neckLace[start] << ' ' ; 
        start = neckLace[start] ; 
    }

}