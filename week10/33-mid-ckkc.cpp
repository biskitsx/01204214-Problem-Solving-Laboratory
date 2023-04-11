#include<iostream>
using namespace std ;

int main() {
    int x ;
    int i ;
    int yearr ;
    cin >> x ;
    for (i = 0 ; i >= 0 ;i++) {
        cin >> yearr ;
        // cout << i << ' ' ;
        if (yearr == 0) {
            break;
        }
    }
    // cout <<endl ;
    // cout << i << endl ;
    // cout  << i%2 << " what \n" ;

    if (i%2 == 0) {
        // cout << "nice/n" ;
        if (x % 2 == 0) {
            cout << 'K' ;
        }
        else {
            cout << 'C' ;
        }
    }
    else {
        if (x % 2 == 0) {
            cout << 'C' ;
        }
        else {
            cout << 'K' ;
        }
    }
}