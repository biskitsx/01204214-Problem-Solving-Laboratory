#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n ,i ,j ,max;
    int codingLevel ; 
    int winnerIndex;  
    vector <int> winner ; 
    int challengerIndex[10000] ; 
    
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
        auto it = upper_bound(winner.cbegin(), winner.cend(), max, greater<int>());
        winner.insert(it, max);
        challengerIndex[max] = winnerIndex ; 
    }

    i = 0;
    for (auto e: winner) {
        if (i==3) {
            cout << challengerIndex[e] ;
            break;  
        }
        cout << challengerIndex[e] << ' '; 
        i++ ;
    }
}