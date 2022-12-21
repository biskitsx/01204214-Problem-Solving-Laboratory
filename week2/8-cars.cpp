#include<iostream>
#include<vector>
using namespace std ;

int main( )  {
    int n , i , quality , price   ;
    vector <int> carQuality ; 
    int cantSold = 0 ;
    cin >> n ;

    for (i=0;i<n;i++){
        cin >> price >> quality ; 
        carQuality.push_back(quality) ; 
    }

    for (i=0;i<n-1;i++) {
        if (carQuality[i] <= carQuality[i+1]) {
            cantSold++ ;
        }
    }

    cout << cantSold <<endl ; 
}