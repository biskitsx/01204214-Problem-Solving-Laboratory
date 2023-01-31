#include<iostream>
using namespace std;

int n, i, j;
long long height[100001] ; 
long long delta[100001] ; 
long long minHeight = 0xfffffff;
long long maxHeight = 0 ; 

int maxIndex ;
int minIndex ;

int sum = 0 ;
void readInput() {
    cin >> n ;
    for (i=0;i<n;i++) {
        cin >> height[i] ;
        if (height[i] < minHeight) {
            minHeight = height[i] ; 
            minIndex = i ;
        }
        if (height[i] > maxHeight) {
            maxHeight = height[i] ; 
            maxIndex = i ;
        }

        if (i == 0 ) {
            continue; 
        }


        // delta[i] = abs(height[i]-height[i-1]) ;
        // sum += delta[i] ; 
    }

}


void findBest() {
    
}

int main() {
    readInput() ; 
    findHeight() ;
}