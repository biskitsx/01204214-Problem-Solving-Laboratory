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
    int n,i,ic ;
    list<int> icList ; 
    string command ; 

    cin >> n ; 
    for (i=0;i<n;i++) {
        cin >> command ; 

        //case 1 push left ,li
        if (command == "li") {
            cin >> ic ;
            icList.push_front(ic) ;
        } 

        //case 2 push right , ri
        else if (command == "ri") { 
            cin >> ic ;
            icList.push_back(ic) ; 
        }

        //case 3 rotate left ,lr
        else if (command == "lr") {
            if (icList.empty()) {
                continue;
            }
            ic = icList.front() ;
            icList.pop_front() ; 
            icList.push_back(ic) ; 
        }

        //case 4 rotate right ,rr
        else {
            if (icList.empty()) {
                continue;
            }
            ic = icList.back() ;
            icList.pop_back() ; 
            icList.push_front(ic) ; 
        }
    }    

    showList(icList) ; 

}