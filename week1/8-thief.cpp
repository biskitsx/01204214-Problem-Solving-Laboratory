#include<iostream>
using namespace std ;

int main() {
    int n,k,t ;

    cin >> n >> k >> t ; 
    
    int currentGift = 1+k ;
    int considered = 2 ;

    while(1) {
        if (currentGift == t || currentGift == 1) {
            if (currentGift==1) {
                considered-- ;
            }
            break ; 
        }
        considered++;
        currentGift = ((currentGift+k)%n) ;

    }
    cout << considered ;

}