#include<iostream>
using namespace std;

int n, x ;
int point[100001] ;
int dp[100001]={-1} ; 

int main() {
    cin >> n ;
    for (int i = 0; i<n ;i++) {
        cin >> point[i] ;
    }

    dp[0] = 0 ;
    for (int i = 1; i < n ;i++) {
        for (int j = 0 ; j < i ;j++) {
            
        }
    }


    cout <<dp[n-1] ; 
}