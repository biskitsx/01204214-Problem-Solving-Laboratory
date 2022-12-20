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
        vector <int> onHandCard ;

        for (i=1;i<=n;i+=2) {
            discardedCard.push_back(i) ;
            if (i!=n) {
                onHandCard.push_back(i+1) ; 
            } 
        }

        int indexStart = 1 ;

        while(1) {
            if (onHandCard.size()==1) {
                break; 
            }
            for (i = indexStart; i <= (onHandCard.size()-1) ; i+=2) {
                discardedCard.push_back(onHandCard[i]) ; 
                // onHandCard.
            }

        }



    }

    
}