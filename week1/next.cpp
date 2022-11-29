#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int findRound(unordered_map <int,int> map , int person) {
    int currentPerson= map[person];
    int round=1 ;
 
    while(1) {
        if (currentPerson == person) {
            return round ; 
        }
        currentPerson = map[currentPerson] ;
        round++ ; 
    }    
}

int main() {
    int next ;
    int n ;
    int maxRound = 0 ;
    int round ;
    unordered_map <int,int> Map ;
    cin >> n ; 
    for (int i = 1 ; i<= n;i++) {
        cin >> next ;
        Map[next] = i ; 
    }
    
    for (int i=n;i>=1;i--) {
        round = findRound(Map,i) ;
        maxRound = round>maxRound ? round : maxRound ;
    }

    cout << maxRound ; 


}