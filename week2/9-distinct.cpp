#include<iostream>
#include<list>
#include<vector>

using namespace std ;

int main() {
    int n , i , j ,price ; 
    int checkPrice[1000001] ;
    int count = 0 ; 
    int sumPrice ; 
    vector<int> priceEachStore ; 

    cin >> n ;
    for (i=0;i<n;++i) {
        cin >> price ;
        priceEachStore.push_back(price) ;
    }

    for (i=0;i<n;++i) { 
        sumPrice = 0 ;
        for (j=i;j<n;++j) {
            sumPrice += priceEachStore[j] ; 
            if (!checkPrice[sumPrice]) {
                count++ ;
                checkPrice[sumPrice]++ ; 
            }
        }
    }

    cout << count ; 


}
