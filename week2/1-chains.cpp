#include<iostream>
#include<list>
using namespace std ; 

void showList(link<int> linkListed) {

}
int main() {
    list<int> linkedList ; 
    int n ,i , num , command; 

    for (i=0;i<n;i++) {
        cin >> command ; 
        if (command == 'I') {
            cin >> num ; 
            linkedList.push_front(num) ; 
        }
    }
    
}