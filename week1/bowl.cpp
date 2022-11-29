#include<iostream>
#include<unordered_map>
using namespace std ;

int main() {
    int n,x,i ;
    unordered_map<int,int> map ; 
    cin >> n ;
    for (i = 0 ; i < n ; i++) {
        cin >> x ;
        map[x]++ ;
    }
    int max = 0 ;
    for (auto e: map) {
        if (e.second > max) {
            max = e.second ;
        }
    }
    cout << max ;
}