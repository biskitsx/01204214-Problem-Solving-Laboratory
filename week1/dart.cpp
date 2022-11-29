#include<iostream>
#include<math.h>
using namespace std ;

int main() {
    int nums,i,x,y ; 
    int totalScore = 0;
    double max ; 
    cin >> nums ; 
    
    for (i = 0; i<nums;i++) {
        cin >> x >> y ;
        max = pow(((x*x)+(y*y)),0.5) ; 
        if (max >10) {
            continue;
        }
        if (max <= 2) {
            totalScore += 5 ;
        }
        else if (max <= 4) {
            totalScore += 4 ;
        }
        else if (max <= 6) {
            totalScore += 3 ;
        }
        else if (max <=8) {
            totalScore += 2 ;
        }
        else if (max <=10) {
            totalScore += 1 ;
        }
    }
    cout << totalScore ; 
}