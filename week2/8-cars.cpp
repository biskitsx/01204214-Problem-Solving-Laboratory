#include<iostream>
#include<vector>
using namespace std ;

int main( )  {
    int n , i , max ; 
    long quality , price   ;
    int cantSold = 0 ;
    vector <long> carQuality ; 

    cin >> n ;

    for (i=0;i<n;i++){
        cin >> price >> quality ; 
        carQuality.push_back(quality) ; 

    }
    
    max = carQuality[n-1] ;
    
    for (i=n-2;i>=0;i--) {
        
        if (carQuality[i] > max) {
            max = carQuality[i] ; 
        }
        else if (carQuality[i] < max) {
            cantSold++ ; 
        }
    }

    cout << cantSold ;
}