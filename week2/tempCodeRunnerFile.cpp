#include<iostream>
#include<list>
using namespace std ; 

list<int> linkedList ;
 
void showList() {
    list<int>:: iterator ptr;

    for (ptr= linkListed.begin(); ptr != linkListed.end(); ptr++){
        cout << *ptr << '\n' ; 
    }
    return ;
}

int findNum(int tg) {
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
        else if (command == 'A') {
            cin >> num ;
            linkedList.push_back(num) ;
        }
        else {
            cin >> num ; 
            if (num > linkedList.size()) {
                continue; 
            }
            linkedList.remove(findNum(num)) ; 
        }
    }
    
    showList() ; 
    return 0 ; 
}