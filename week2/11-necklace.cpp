#include<iostream>
#include<list>
#include<vector>
using namespace std ; 

void showList(list<int> linkListed) {
    list<int>:: iterator ptr;

    for (ptr= linkListed.begin(); ptr != linkListed.end(); ptr++){
        cout << *ptr << ' ' ; 
    }

    cout << '\n' ; 
    return ;
}


int main() {
    int n,i ,begin,next; 
    vector <list<int> > beadLine ; 

    cin >> n ;


    for (i=0;i<n-1;++i) {
        cin >> next >>  begin; 

    }


}