#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std ; 

void showList(list<int> linkListed) {
    if (linkListed.empty()) {
        cout << '\n' ; 
        return ; 
    }
    list<int>:: iterator ptr;
    cout << ' ' ; 
    for (ptr=linkListed.begin(); ptr != linkListed.end(); ptr++){
        if (ptr != linkListed.begin()) {
            cout << ", " << *ptr ; 
        }
        else {
            cout << *ptr ;
        }
    }
    cout << '\n' ; 
    return ;
}


int main() {
    int n, i ;

    vector < pair <int,list<int> > > decks ;

    while(1) {

        cin >> n ;
        if (n==0 ) {
            
            break; 
        }
        

        list<int> onHandCards ; 
        list<int> discardedCards ; 
        pair <int,list<int> > deck;

        for (i=1;i<=n;i++) {
            onHandCards.push_back(i) ; 
        }

        while(onHandCards.size()!=1) {
            discardedCards.push_back(onHandCards.front()) ; 
            onHandCards.pop_front() ; 
            onHandCards.push_back(onHandCards.front()) ; 
            onHandCards.pop_front() ; 
        }

        deck.first = onHandCards.front(); 
        deck.second = discardedCards ; 

        decks.push_back(deck) ; 
        // showList(discardedCards) ; 
    }

    for (auto e : decks) {
        cout << "Discarded cards:" ;
        showList(e.second) ;
        
        cout << "Remaining card: " << e.first << endl ;
    }





}