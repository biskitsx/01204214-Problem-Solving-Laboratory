#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int n ;
vector<int> price ;
int dp[201] = {0}; 
int check[301] = {0} ;

int maxValue() {

    for (int i = 0 ; i < n ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            int inDex = price[i] + price[j] ;
            if (check[inDex] != 0) {
                return inDex;
            }
            check[inDex]++ ;
        }
    }
    return 0;
}

int main() {
    cin >> n ;
    price.resize(n+1) ;
    for (int i = 0 ; i < n ; i++) {
        cin >> price[i] ;
    }
    sort(price.begin(),price.end(),greater<int>()) ;
    cout << maxValue();
}