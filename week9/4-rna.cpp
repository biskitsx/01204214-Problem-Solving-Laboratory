#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

const int N = 205;
int n, dp[N][N];

bool match(char a, char b) {
    return (a == 'A' && b == 'U') || (a == 'U' && b == 'A') || (a == 'C' && b == 'G') || (a == 'G' && b == 'C');
}

int solve(int i, int j, string &s) {
    if (i >= j) 
        return 0;
    if (dp[i][j] != -1) 
        return dp[i][j];
    int ans = solve(i+1, j, s);
    
    for (int k = i+4; k <= j; k++) {
        if (match(s[i], s[k])) {
            ans = max(ans, 1 + solve(i+1, k-1, s) + solve(k+1, j, s));
        }
    }

    return dp[i][j] = ans;
}

int main() {
    string s;
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n-1, s) << endl;
    return 0;
}
