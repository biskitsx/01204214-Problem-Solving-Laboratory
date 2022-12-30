#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n ,i ,j ,max;
    int codingLevel ; 
    int winnerIndex;  
    int winner[1000000] ; 
    int challengerIndex[1000000] ; 
    
    cin >> n ;

    for (i=0;i<4;i++) {
        max = 0 ;
        for (j=0;j<n;j++) {
            cin >> codingLevel ; 
            if (max < codingLevel) {
                max = codingLevel ; 
                winnerIndex = i*n + j + 1 ;
            }
        }
        winner[i] = max ;
        challengerIndex[max] = winnerIndex ; 
    }

    int a = winner[0] > winner[1] ? winner[0] : winner[1] ;
    int b = winner[2] > winner[3] ? winner[2] : winner[3] ;
    int f = a > b ? a : b ; 
    int s = a < b ? a : b ;
    a = winner[0] > winner[1] ? winner[1] : winner[0] ; 
    b = winner[2] > winner[3] ? winner[3] : winner[2] ; 
    


    cout << challengerIndex[f] << ' ' ;
    cout << challengerIndex[s] << ' ' ;
    cout << challengerIndex[a] << ' ' ;
    cout << challengerIndex[b] ;

    


}