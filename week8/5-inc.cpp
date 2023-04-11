#include <iostream>
#include<set> 
using namespace std;

const int MAXN = 1001;
int n, x;
int maxId ;
int a[MAXN], dp[MAXN];
int parent[1001] = {-1}; 
set <int> res ;

void readInput(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int main(){

    readInput();
    for (int i = 0 ; i < n ; i++) {
        dp[i] = 1 ;
        for (int j = 0 ; j < i ; j++) {
            //can pick
            if (a[j] < a[i]) {
                //be worth
                if (dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1 ;

                    parent[i] = j ;
                    maxId = i ;
                }
                //not be worth
                else {

                }
            }
            //can't pick
            else {

            }
        }
    }
    cout << dp[n-1] <<endl;

    int x = maxId ;
    while(parent[x] != -1) {
        res.insert(a[x]) ;
        x = parent[x] ; 
    }


    cout << 
    for (auto e : res) {
        cout << e << ' ' ;
    }
    return 0;
}
