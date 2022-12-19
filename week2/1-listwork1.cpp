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

int findNum(list<int> linkListed,int tg) {
    list<int>:: iterator ptr;
    int index = 0; 
    for (ptr= linkListed.begin(); ptr != linkListed.end(); ptr++){
        if (index == tg -1 ) {
            return *ptr ;
        }
        ++index ; 
    }
    return -1 ;
}


int main() {
    list<int> linkedList ; 
    int n ,i , num ;
    char command ; 
    cin >> n ;
    for (i=0;i<n;i++) {
        cin >> command ; 
        if (command == 'I') {
            // cout << "nice\n" ;
            cin >> num ; 
            linkedList.push_front(num) ; 
        }
        else {
            cin >> num ; 
            linkedList.remove(findNum(linkedList,num)) ; 
        }
    }
    
    showList(linkedList) ; 
}