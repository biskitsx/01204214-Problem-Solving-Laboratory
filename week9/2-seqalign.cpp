#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string X, Y;
    cin >> X >> Y;

    int n = X.size(), m = Y.size();

    int dp[n+1][m+1] ;

    // กำหนดค่าเริ่มต้น
    for (int i = 1; i <= n; i++) 
        dp[i][0] = i;
    for (int j = 1; j <= m; j++) 
        dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i-1][j-1] + (X[i-1] != Y[j-1]), min(dp[i-1][j] + 1, dp[i][j-1] + 1));
        }
    }

    cout << dp[n][m] << endl;
    // แสดงตาราง
    // cout << "    " ;

    // for (int i = 0 ; i < m ;i++) {
    //     cout << Y[i] << ' ';
    // }
    // cout <<endl;
    // for (int i = 0; i <= n; i++) {
    //     if (i==0) {
    //         cout << "  " ;
    //     }
    //     else 
    //         cout << X[i-1] << ' ' ;
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl ;
    // }
    return 0;
}
