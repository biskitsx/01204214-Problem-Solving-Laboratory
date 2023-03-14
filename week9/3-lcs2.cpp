#include<iostream>
#include<vector>
using namespace std ;

string s, t ;
vector <char>  o ; 
int dp[201][201] ;
int sizeS, sizeT ; 
int now = 0 ;
int maxCurrent = 0 ; 

void printMatrix() {
    cout << "    " ;
    for (int i = 0 ; i < sizeS;i++) {
        cout << s[i] << " "; 
    }
    cout << endl ;
    for (int i = 0; i <=  sizeT ;i++) {
        if (i < 1) {
            cout << "  " ;
        }
        else 
            cout << t[i-1] <<' '; 

        for (int j = 0 ; j <= sizeS ; j++) {
            cout << dp[i][j] << ' ' ;
        }
        cout << endl ;
    }
}

string longestSubSequence() {
    string res = "" ;
    int i =  sizeT,j =  sizeS ;

    while(i>0 && j > 0) {
        if (s[j-1] == t[i-1]) {
            res = s[j-1] + res ;
            i-- ;
            j-- ;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i-- ;
        }
        else {
            j-- ;
        }
    }
    return res ;
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
    cout << dp[sizeT][sizeS] << endl ; 
    cout << longestSubSequence() ; 
}