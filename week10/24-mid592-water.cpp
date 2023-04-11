#include<iostream>
using namespace std ;

int main() {
    int n ;
    int water[1001] ;
    int total = 0 ;
    cin >> n ;
    
    for (int i = 0 ; i < n ; i++) {
        cin >> water[i] ; 
    }

    for (int i = 1 ; i < n ; i++) {

        int delta = water[i-1] - water[i] ; 
        if (delta >= 10) {
            if (delta > 70) {
                delta = 70 ;
            }
            total += delta ;
            // cout << total << ' ' << water[i] << ' ' << water[i-1] <<endl; 
        }
    }

    cout << total*10 ;
}