#include<iostream>
#include<vector>
using namespace std ;

int main( )  {
    int n , i ; 
    long long quality , price   ;
    int cantSold = 0 ;
    vector <long long> carQuality ; 

    cin >> n ;

    for (i=0;i<n;i++){
        cin >> price >> quality ; 
        carQuality.push_back(quality) ; 

        if (i!=0) {
            if (carQuality[i]> carQuality[i-1]) {
                cantSold++ ; 
            }
        }
    }


    cout << cantSold <<endl ; 
}