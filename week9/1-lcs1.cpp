#include<iostream>
using namespace std ;

string s, t; 
int dp[201][201] ;
int sizeS, sizeT ; 
int now = 0 ;

void printMatrix() {
    for (int i = 0; i <=  sizeS ;i++) {
        for (int j = 0 ; j <= sizeT ; j++) {
            cout << dp[i][j] << ' ' ;
        }
        cout << endl ;
    }
}

int main() {
    cin >> s >> t ;

    sizeS = s.size() ;
    sizeT = t.size() ;

    for (int j = 1 ; j <= sizeT ; j++ ) {
        for (int i = 1 ; i <= sizeS ; i++) {
            if (s[i-1] == t[j-1]) {
                dp[j][i] = max (max(dp[j-1][i],dp[j][i-1]),dp[j-1][i-1]+1)  ;
            }
            else {
                dp[j][i] = max (dp[j-1][i],dp[j][i-1]) ;
            }
        }
    }
    // printMatrix() ;
    cout << dp[sizeT][sizeS] ; 
}