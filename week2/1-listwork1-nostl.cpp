#include<iostream>
#include<list>
using namespace std ; 

void showList(list<int> linkListed) {
    list<int>:: iterator ptr;

    for (ptr= linkListed.begin(); ptr != linkListed.end(); ptr++){
        cout << *ptr << '\n' ; 
    }
    return ;
}

int main() {
    list<int> linkedList ; 
    int n ,i , num ;
    char command ;

    cin >> n ;
    for (i=0;i<n;i++) {
        cin >> command ; 
        if (command == 'I') {
            cin >> num ; 
            linkedList.push_front(num) ; 
        }
        else {
            cin >> num ; 
            if (num > linkedList.size()) {
                continue;
            }
            list<int>:: iterator it1 = linkedList.begin() ;
            advance(it1,num-1); 
            linkedList.erase(it1) ; 
        }
    }
    
    showList(linkedList) ;
    return 0 ;
}