#include<iostream>
using namespace std ;

int main() {
    string text ;
    int i, k  ; 
    int N = 0 , E = 0 , S = 0 , W = 0 ; 
    int lenghtY, lenghtX ;
    cin >> text ;
    cin >> k ; 
    for (i=0;i<text.size();i++) {

        if ('E' == text[i]) {
            E++;
        }
        else if ('W' == text[i]) {
            W++;
        }

        else if ('N' == text[i]) {
            N++ ;
        }
        else if ('S' == text[i]) {
            S++ ;
        }
    }

    //consider y
    if (S==0||N==0) {
        lenghtY = N > S ? N : S ;
    }

    else {
        int diffSN = abs(S-N) ; 
        int maxSN = N > S ? N : S ;
        int minSN = N < S ? N : S ;

        if (minSN > k) {
            minSN -= k ;
            k = 0 ;
        }
        else {
            k -= minSN ;
            minSN =0 ;
        }

        lenghtY = maxSN - minSN ; 
    }


    if (E==0||W==0) {
        lenghtX = E > W ? E : W ;
    }

    else {
        int diffEW = abs(E-W) ; 
        int maxEW = E > W ? E : W ;
        int minEW = E < W ? E : W ;

        if (minEW > k) {
            minEW -= k ;
            k = 0 ;
        }
        else {
            k -= minEW ;
            minEW =0 ;
        }
        lenghtX = maxEW - minEW ;
    }

    cout << (lenghtX+lenghtY-k)*2 ; 

}