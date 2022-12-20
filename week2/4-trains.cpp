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

void showMap(list<int> chanChala[100001]) {
    int i ;
    for (i=0;i<100001;i++) {
        if (chanChala[i].empty()) {
            continue;
        }

        showList(chanChala[i]) ; 
    }
}

int main() {
    int n , index ;
    int i , j ; 
    char command ; 

    list<int> chanChala[100001] ; 

    cin >> n  ;
    for (index = 0 ; index < n ; index++) {
        cin >> command >> i >> j ; 
        
        //insert a train to chanchala
        if (command=='N') {
            chanChala[j].push_back(i) ; 
            // cout << "what\n" ; 
        }

        else if (command=='M') {
            chanChala[j].splice(chanChala[j].end(),chanChala[i]) ; 
        }
    }


    showMap(chanChala) ;


}