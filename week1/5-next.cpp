#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int main() {
    int next,n ;
    int maxRound = 0 ;

    unordered_map <int,int> Map ;
    unordered_map <int,int> passed ;
    
    //input
    cin >> n ; 
    for (int i = 1 ; i<= n;i++) {
        cin >> next ;
        Map[next] = i ; 
    }
    
    //find round
    for (int i=1;i<=n;i++) {
        if (passed[i]==1) {
            continue;
        }

        int person = i ;
        int round = 1 ;
        int currentPerson = Map[person] ;
        passed[currentPerson]++ ;


        //find round 
        while(1) {
            if (currentPerson == person) {
                break ;
            }
            currentPerson = Map[currentPerson] ; ;
            passed[currentPerson]++ ;
            round++ ; 
        }

        //find Max round 
        maxRound = round>maxRound ? round : maxRound ;
    }
    cout << maxRound ; 
}