#include<iostream>
#include<vector>
using namespace std ;


int main() {
    int n,i,j,angle ; 
    int intersection = 0 ;
    vector <int> penguin ;
    
    cin >> n  ;
    for (i=0;i<n;i++) {
        cin >> angle;
        penguin.push_back(angle);  
    }

    for (i=0;i<n-1;i++) {
        for (j=i+1;j<n;j++) {
            if (penguin[i] < penguin[j]) {
                intersection++ ;
            }
        }
    }
    cout << intersection ;

}