#include<iostream>
#include<vector>
using namespace std ;

int n, m;
vector <int> table ; 

void readInput() {
    cin >> n >> m ;
    table.resize(n+1);
    
    for (int i=1 ; i<=n ; i++) {
        cin >> table[i] ;
    }
}

int main() {
    readInput();
    int current = 0 ;
    int roll ;
    for (int i=0 ; i<m ;i++) {
        cin >> roll ;
        current += roll ;
        if  (current > 0 && current < n) {
            current += table[current];
        }

        if (current > n) {
            current = n;
        }
        else if (current < 1) {
            current = 0 ;
        }


    }

    cout << current ;
}