#include<iostream>
using namespace std ;

int main() {
    string text ;
    int x=0, y=0, i, k  ; 
    cin >> text ;
    cin >> k ; 
    for (i=0;i<text.size();i++) {
        if ('E' == text[i]) {
            x++ ;
        }
        else if ('W' == text[i]) {
            x-- ;
        }


        else if ('N' == text[i]) {
            y++ ; 
        }
        else if ('S' == text[i]) {
            y-- ; 
        }


    }
    cout << (abs(x) + abs(y) + k)*2 ;
    
    
}