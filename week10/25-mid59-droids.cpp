#include<iostream>
#include<vector>
using namespace std ;

int m, n, x;
vector <int> pikat ;
void readInput() {
    cin >> n >> m;
    pikat.resize(n+1);
    for (int i = 1; i<=n ;i++) {
        cin >> pikat[i] ;
    }
}

int main() {
    readInput();

    int used = -1 ;
    int summ = 0;
    for (int i = 0 ; i<m ;++i) {
        cin >> x;
        
        int minny = 10000000 ;
        int minnyIndex ;
        for (int j = 1 ; j <= n ; j++) {
            int distance = abs(pikat[j]-x) ;
            if (distance < minny && used != j) {
                minny = distance ;
                minnyIndex = j ;
            }
        }
        summ += minny ;
        used = minnyIndex ;

    }

    cout << summ ;
}