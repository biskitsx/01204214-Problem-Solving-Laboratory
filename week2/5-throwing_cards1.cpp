#include<iostream>
#include<vector>

using namespace std ; 

void showVector(vector<int> discardedCard) {
    for (auto e : discardedCard) {
        cout << e << ' ' ;
    }
    cout << '\n' ; 
}

int main() {
    int n,i ;
    while(1) {
        cin >> n ; 
        if (n == 0) {
            break; 
        }
        
        vector <int> discardedCard ;
        for (i=1;i<=n;i+=2) {
            discardedCard.push_back(i) ; 
        }
        showVector(discardedCard) ; 



    }

    
}