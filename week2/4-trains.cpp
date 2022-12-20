#include<iostream>
#include<unordered_map>
#include<list>
using namespace std ; 


void showList(list<int> linkListed) {
    list<int>:: iterator ptr;

    for (ptr=linkListed.begin(); ptr != linkListed.end(); ptr++){
        cout << *ptr << '\n' ; 
    }
    return ;
}

void showMap(unordered_map<int,list<int> > allChanchala) {
    for (auto e : allChanchala) {
        showList(e.second) ; 
    }
}

int main() {
    int n , index ;
    int i , j ; 
    char command ; 

    unordered_map <int,list<int> > chanChala ; 

    cin >> n  ;
    for (index = 0 ; index < n ; index++) {
        cin >> command >> i >> j ; 
        
        //insert a train to chanchala
        if (command=='N') {
            chanChala[j].push_back(i) ; 
            cout << "what\n" ; 
        }

        else if (command=='M') {
            chanChala[j].splice(chanChala[j].end(),chanChala[i]) ; 
        }
        // showMap(chanChala) ;
    }

    // showMap(chanChala)  ;    
}